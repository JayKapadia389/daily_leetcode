// O(n) time, O(n) space
//
// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         unordered_set<int> s;
//         for(auto num : nums){
//             if(s.find(num) != s.end()) return num;
//             s.insert(num);
//         }
//         return -1;
//     }
// };

// O(n) time, O(1) space - Using pigeon hole principle
//
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if ((i - 1 >= 0 && nums[i - 1] == nums[i]) ||
                (i - 2 >= 0 && nums[i - 2] == nums[i]) ||
                (i - 3 >= 0 && nums[i - 3] == nums[i])){
                    return nums[i];
                }
        }
        return -1;
    }
};