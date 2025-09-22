class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        int mx_freq = 0;

        for(auto num : nums){
            ++freq[num];
            mx_freq = max(mx_freq, freq[num]);
        }

        int cnt = 0;
        for(int i = 1; i <= 100; ++i){
            if(freq[i] == mx_freq) ++cnt;
        }

        return mx_freq * cnt;
    }
};