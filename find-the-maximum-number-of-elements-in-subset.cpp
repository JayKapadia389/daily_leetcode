class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        unordered_map<int, int> freq;

        for(auto num : nums){
            ++freq[num];
        }

        if(freq.find(1) != freq.end()){
            ans = max(ans, (freq[1] % 2 == 0)? freq[1] - 1 : freq[1]);
        }

        for(auto num : nums){
            if(num == 1) continue;

            int len = 1;
            long long num2 = num;

            while(freq[num2] > 1 && (num2 = num2 * num2) <= 1e9 && freq.find(num2) != freq.end()){
                len += 2;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};