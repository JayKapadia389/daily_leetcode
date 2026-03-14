class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = INT_MIN, n = nums.size();

        for(auto num : nums){
            mx = max(mx, num);
            prefixGcd.push_back(gcd(mx, num));
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;

        for(int i = 0; i < n/2; ++i){
            sum += gcd(prefixGcd[i], prefixGcd[n-i-1]);
        }

        return sum;
    }
};