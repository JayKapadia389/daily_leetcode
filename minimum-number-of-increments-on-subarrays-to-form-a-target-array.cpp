class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0, ans = 0;

        for(auto num : target){
            ans += max(0, num - prev);
            prev = num;
        }
        
        return ans ;
    }
};