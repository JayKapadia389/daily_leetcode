class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> pair_wise_xor;
        int n = nums.size();
        vector<bool> pair_wise_xor_s(2 << 11, false);

        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                int xr = (nums[i] ^ nums[j]); 
                if(!pair_wise_xor_s[xr]){
                    pair_wise_xor_s[xr] = true;
                    pair_wise_xor.push_back(xr);
                }
            }
        }

        vector<bool> unique_triplets(2 << 11, false);
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            for(auto p : pair_wise_xor){
                int xr = (nums[i] ^ p);
                if(!unique_triplets[xr]){
                    unique_triplets[xr] = true;
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};