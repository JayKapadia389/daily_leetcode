class Solution {
public:
    string lexSmallest(string s) {
        int n = s.length();
        vector<string> v;

        for(int i = 1; i <= n; ++i){
            string temp = s;
            reverse(temp.begin(), temp.begin()+i);
            v.push_back(temp);
        }

        for(int i = 0; i < n; ++i){
            string temp = s;
            reverse(temp.begin() + i, temp.end());
            v.push_back(temp);
        }

        sort(v.begin(), v.end());

        return v[0];
    }
};