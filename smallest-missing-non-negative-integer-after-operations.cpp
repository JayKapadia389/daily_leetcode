class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> m;

        for(auto num : nums){
            int rem = num % value;

            if(rem < 0){
                rem += value;
            }

            ++m[rem];
        }

        for(int i = 0; i <= nums.size(); ++i){
            int rem = i%value;

            if(m[rem] > 0){
                --m[rem];
            }
            else{
                return i;
            }
        }
        return -1;
    }
};