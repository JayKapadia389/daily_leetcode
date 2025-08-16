class Solution {
public:

    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    void nextPermutation(vector<int>& nums) {
        int idx = -1, n = nums.size();

        if(n == 1)
            return;

        for(int i = n - 2; i >= 0; --i){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx != -1){
            int i = n - 1;
            for(; i > idx; --i){
                if(nums[i] > nums[idx]){
                    break;
                }
            }

            swap(nums[i], nums[idx]);
        }

        sort(nums.begin() + (idx + 1) , nums.end());
    }
};