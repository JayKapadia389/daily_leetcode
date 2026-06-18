class Solution {
string s_, p_;
int n_, m_;
vector<vector<int>> dp_;

bool fun(int i, int j) {
    cout << i << " " << j << endl;
    if(dp_[i][j] != -1) return dp_[i][j] == 1;

    if(j == m_){ // n
        return (i == n_); // a, n
    }

    if(p_[j] == '.'){
        if(j + 1 != m_ && p_[j + 1] == '*'){ // .*
            for(int v = i; v <= n_; ++v){
                if(fun(v, j + 2)){
                    dp_[i][j] = 1;
                    return true; 
                }
            }

            dp_[i][j] = 0;
            return false;
        }
        else{ // .n, .b, ..
            if(i == n_){
                dp_[i][j] = 0;
                return false;
            }

            if(fun(i + 1, j + 1)){
                dp_[i][j] = 1;
                return true;
            }
            dp_[i][j] = 0;
            return false;
        }
    }
    else{ // p[j] != '.'
        if(j + 1 != m_ && p_[j + 1] == '*'){ // a*
            int v = i;
            while(v != n_ + 1) {
                if(fun(v, j + 2)){
                    dp_[i][j] = 1;
                    return true;
                }
                if(v != n_ && s_[v] != p_[j]){
                    break;
                }
                ++v;
            }
            dp_[i][j] = 0;
            return false;
        }
        else { // ab, a., an
            if(i == n_){
                dp_[i][j] = 0;
                return false;
            }

            if(s_[i] == p_[j]){
                if(fun(i+1, j+1)){
                    dp_[i][j] = 1;
                    return true;
                }
                dp_[i][j] = 0;
                return false;
            }
            dp_[i][j] = 0;
            return false;
        }
    } 
}

public:
    bool isMatch(string s, string p) {
        s_ = s;
        p_ = p;
        n_ = s.length();
        m_ = p.length();
        dp_ = vector<vector<int>>(n_ + 1, vector<int>(m_ + 1, -1));
        return fun(0, 0);
    }
};