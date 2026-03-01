class Solution {
public:
    int minPartitions(string n) {
        char mx = '0';
        for(auto num : n ){
            mx = max(mx, num);
        }
        return mx - '0';
    }
};