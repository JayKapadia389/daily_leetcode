// Solution 1
class Solution {
private:
int countSetBits(int i){
    int cnt = 0;
    while(i != 0){
        cnt += (i & 1);
        i >>= 1;
    }
    return cnt;
}

public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int i = 0; i < 12; ++i){
            for(int j = 0; j < 60; ++j){
                if(turnedOn == (countSetBits(i) + countSetBits(j))){
                    string s = to_string(i) + ":" + ((j < 10)? "0" : "") + to_string(j);
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};

// Solution 2
// uses in-built method.
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i = 0; i < 12; ++i){
            for(int j = 0; j < 60; ++j){
                if(turnedOn == (__builtin_popcount(i) + __builtin_popcount(j))){
                    ans.push_back(to_string(i) + ":" + ((j < 10)? "0" : "") + to_string(j));
                }
            }
        }
        return ans;
    }
};