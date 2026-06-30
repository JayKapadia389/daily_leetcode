class Solution {
private:
bool isValid(vector<int> freq) {
    return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
}

public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        int l = 0, r = 0;
        vector<int> freq(3, 0);

        while(r < n){
            ++freq[s[r] - 'a'];

            while(isValid(freq)){
                --freq[s[l] - 'a'];
                ++l;
            }

            cnt += l;
            ++r;
        }

        return cnt;
    }
};