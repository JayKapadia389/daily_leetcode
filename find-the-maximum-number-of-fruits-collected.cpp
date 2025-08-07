class Solution {
private:
    vector<vector<int>> dp_;
    vector<vector<int>> fruits_;
    int n_;

    int dp3(int i , int j){
        if((i >= n_ || j < 0) || (j+1 < n_ - i)){
            return 0;
        }

        if(dp_[i][j] != -1){
            return dp_[i][j];
        }

        return (dp_[i][j] = (fruits_[i][j] + max({dp3(i-1,j-1), dp3(i,j-1), dp3(i+1,j-1)})));
    }

    int dp2(int i , int j){
        if((j >= n_ || i < 0) || (i+1 < n_ - j)){
            return 0;
        }
        
        if(dp_[i][j] != -1){
            return dp_[i][j];
        }

        return (dp_[i][j] = (fruits_[i][j] + max({dp2(i-1,j-1), dp2(i-1,j), dp2(i-1,j+1)})));
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ans = 0; 
        n_ = fruits.size();
        dp_ = vector<vector<int>>(n_, vector<int>(n_,-1));
        fruits_ = fruits;

        for(int i = 0; i < n_; ++i){
            ans += fruits[i][i];
        }

        ans+=dp2(n_-2, n_-1);
        ans+=dp3(n_-1,n_-2);
        return ans;
    }
};