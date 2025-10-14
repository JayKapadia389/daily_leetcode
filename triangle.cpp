class Solution {
private:
vector<vector<int>> memo_;
int n_;

int find(vector<vector<int>>& triangle, int i, int j){
    if(i == n_) 
        return 0;
    else if(memo_[i][j] != INT_MAX) 
        return memo_[i][j];
    
    int l = find(triangle, i+1, j);
    int r = find(triangle, i+1, j+1);

    return memo_[i][j] = triangle[i][j] + min(l, r);
}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n_ = triangle.size();
        memo_ = vector<vector<int>>(200, vector<int>(200, INT_MAX));

        return find(triangle, 0, 0);
    }
};