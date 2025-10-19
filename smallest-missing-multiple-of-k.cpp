class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i = 1;

        while(true){
            bool found = 0;
            int find = k*i;
            
            for(auto num : nums){
                if(num == find){
                    found = 1;
                    break;
                }
            }

            if(!found){
                return find;
            }
            ++i;
        }
    }
};