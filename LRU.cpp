class LRUCache {
    class node {
        public:
        int key;
        int val;
        node* prev;
        node* next;

        node(int k , int v){
            key = k;
            val = v;
        }
    };


    int cap;
    unordered_map<int,node*> m;

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode){
        node* nxt = head->next;
        newnode->next = nxt;
        newnode->prev = head;
        nxt->prev = newnode;
        head->next = newnode;
    }

    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int _key) {
        if(m.find(_key)!=m.end()){
            node* resnode = m[_key];
            int value = resnode->val;
            m.erase(_key);
            deletenode(resnode);
            addnode(resnode);
            m[_key] = head->next;
            return value;
        }
        return -1;
    }

    void put(int _key, int value) {
        if(m.find(_key)!=m.end()){
            node* resnode = m[_key];
            m.erase(_key);
            deletenode(resnode); 
        }
        else{
            if(m.size()==cap){
                node* tailprev = tail->prev;
                m.erase(tailprev->key);
                deletenode(tail->prev);

            }
        }
        addnode(new node(_key,value));
        m[_key] = head->next;

    }
};