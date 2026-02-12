// Solution 1: 
// Top down 3D-DP

const int OFFSET = 1;

class Solution {
private:
int n_, m_; 
string s1_, s2_, s3_;
vector<vector<vector<int>>> dp_;

bool fun(int i ,int j, bool turn){
    if(i == n_-1 && j == m_-1){
        return true;
    }

    if(dp_[i+OFFSET][j+OFFSET][turn] != -1){
        return dp_[i+OFFSET][j+OFFSET][turn];
    }

    int base = i + j + 1;
    const string& s = turn? s2_ : s1_;
    int k = turn? j : i;
    int n = turn? m_ : n_;
    
    for(int p = 1; ((k + p) < n) && (s[k + p] == s3_[base + p]); ++p){
        if(fun(turn? i : (k+p), turn? (k+p) : j,!turn)){
            return (dp_[i+OFFSET][j+OFFSET][turn] = true);
        }
    }

    return (dp_[i+OFFSET][j+OFFSET][turn] = false);
}

public:
    bool isInterleave(string s1, string s2, string s3) {
        n_ = s1.length(), m_ = s2.length();
        dp_ = vector<vector<vector<int>>>(n_+1, vector<vector<int>>(m_+1, vector<int>(2, -1)));

        if((n_ + m_) != s3.length()){
            return false;
        }

        s1_ = s1;
        s2_ = s2;
        s3_ = s3;

        return (fun(-1,-1, 0) || fun(-1, -1, 1));
    }
};