class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> set;
        int n = s.length(); // length() return size_t (which is unsigned). Always cast it int to avoid issues.

        // s.length() - k causes problem when k > s.length().
        for(int i = 0; i <= (n - k); ++i){
            set.insert(s.substr(i, k));
        }

        return (set.size() == pow(2, k));
    }
};