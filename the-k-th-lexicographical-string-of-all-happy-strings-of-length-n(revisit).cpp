class Solution {
public:
    bool recc(string str, int len, int& cnt, string& ans,const int& n, const int& k){
        if(len == n){
            ++cnt;
            if(cnt == k){
                ans = str;
                return true;
            }
            return false;
        }

        if((len == 0 || str.back() != 'a') && recc(str + 'a', len + 1, cnt, ans, n, k)){
            return true;
        }

        if((len == 0 || str.back() != 'b') && recc(str + 'b', len + 1, cnt, ans, n, k)){
            return true;
        }

        if((len == 0 || str.back() != 'c') && recc(str + 'c', len + 1, cnt, ans, n, k)){
            return true;
        }

        return false;
    } 

    string getHappyString(int n, int k) {
        string ans = "";
        int cnt = 0;
        recc("", 0, cnt, ans, n, k);

        return ans;
    }
};