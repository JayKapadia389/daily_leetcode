class Solution {
private:
int poured_;
vector<vector<double>> dp_;

double dp(int i, int j){
    if(i < 0 || j < 0 || j > i){
        return 0;
    }

    if(i == 0 && j == 0){
        return (dp_[i][j] = poured_);
    }

    if(dp_[i][j] != -1){ 
        return dp_[i][j];
    }

    double l = dp(i-1, j-1);
    double r = dp(i-1, j);

    return dp_[i][j] = (max(0.0, l - 1)/2.0) + (max(0.0, r - 1)/2.0);
}

public:
    double champagneTower(int poured, int query_row, int query_glass) {
        dp_ = vector<vector<double>>(100, vector<double>(100, -1));
        poured_ = poured;
        return min(1.0, dp(query_row, query_glass));
    }
};