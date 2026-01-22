class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while(true){
            bool asc = 1;
            int mn_pair = -1;
            int mn_pair_sum = INT_MAX;

            // determine if non-dec order and find minimum sum adjacent pair
            for(int i = 1; i < nums.size(); ++i){
                if(nums[i] < nums[i-1]) asc = 0;
                if((nums[i] + nums[i-1]) < mn_pair_sum){
                    mn_pair = i;
                    mn_pair_sum = nums[i] + nums[i-1];
                }
            }

            // if non-dec then return the `cnt` (number of operations)
            if(asc) return cnt;

            // prepare new array
            nums[mn_pair - 1] = mn_pair_sum;
            nums.erase(nums.begin() + mn_pair);

            ++cnt;
        }
    }
};

// // Use Linked-list for O(1) deletion. Overall complexity still remains o(n^2) but deletion becomes faster.

// class Solution {
// public:
//     int minimumPairRemoval(std::vector<int>& nums) {
//         int n = nums.size();
//         std::vector<int> next(n);
//         std::iota(next.begin(), next.end(), 1);
//         next[n - 1] = -1;
//         int count = 0;

//         while (n - count > 1) {
//             int curr = 0;
//             int target = 0;
//             int targetAdjSum = nums[target] + nums[next[target]];
//             bool isAscending = true;

//             while (curr != -1 && next[curr] != -1) {
//                 if (nums[curr] > nums[next[curr]]) {
//                     isAscending = false;
//                 }

//                 int currAdjSum = nums[curr] + nums[next[curr]];
//                 if (currAdjSum < targetAdjSum) {
//                     target = curr;
//                     targetAdjSum = currAdjSum;
//                 }
//                 curr = next[curr];
//             }

//             if (isAscending) {
//                 break;
//             }

//             count++;
//             next[target] = next[next[target]];
//             nums[target] = targetAdjSum;
//         }

//         return count;
//     }
// };