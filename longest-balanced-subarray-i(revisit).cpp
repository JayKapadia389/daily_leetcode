class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int len = 0, n = nums.size();

        for(int i = 0; i < n; ++i){
            unordered_set<int> s;
            int o = 0, e = 0;

            for(int j = i; j < n; ++j){
                if(!s.contains(nums[j])){
                    s.insert(nums[j]);
                    if(nums[j] % 2 == 0){
                        ++e;
                    }
                    else{
                        ++o;
                    }
                }

                if(o == e){
                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};