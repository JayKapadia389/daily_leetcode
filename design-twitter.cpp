class Twitter {
public:

    map<int , map<int, bool>> followMap ;
    vector<pair<int , int>> posts ; //{post-id , userid}

    int size ;

    bool follows(int follower , int followee ){

        if(follower == followee || followMap[follower][followee]){
            return true ;
        }
        return false ;

    }

    Twitter() {

        size = 0 ;
        
    }
    
    void postTweet(int userId, int tweetId) {

        posts.push_back({tweetId , userId}) ;
        size++ ;
        
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> feed ;
        int c = 0 ;

        for(int i = size - 1 ; i >= 0 && c != 10; i--){

            if(follows(userId , posts[i].second)){
                feed.push_back(posts[i].first) ;
                c++ ;
            }

        }

        return feed ;
        
    }
    
    void follow(int followerId, int followeeId) {

        followMap[followerId][followeeId]  = 1;
        
    }
    
    void unfollow(int followerId, int followeeId) {

        followMap[followerId][followeeId]  = 0;
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */