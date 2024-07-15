class Twitter {
    map<int,set<int>> followers;
    int curr ;
    priority_queue <pair<int,pair<int,int>>> timeline;
public:
    Twitter() {
        curr=  0;
    }

    void postTweet(int userId, int tweetId) {
        timeline.push({curr++,{userId,tweetId}});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue <pair<int,pair<int,int>>> pq= timeline;
        int n=0;

        while(!pq.empty() && n<10){
            auto latest = pq.top();
            pq.pop();

            int tweetUser = latest.second.first;
            if(tweetUser == userId || followers[userId].count(tweetUser)){
                ans.push_back(latest.second.second);

                n++;
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
