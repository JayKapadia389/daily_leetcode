class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n, 0);
        vector<long long> right(n, 0);

        unordered_map<int, pair<int, int>> m;

        for(int i = 0; i < n; ++i){
            int num = nums[i];
            if(m.find(num) != m.end()){
                auto [prev_idx, freq] = m[num];
                left[i] = left[prev_idx] + (long long)freq * (i - prev_idx);
            }
            m[num].first = i;
            ++(m[num].second);
        }

        m.clear();

        for(int i = n - 1; i >= 0; --i){
            int num = nums[i];
            if(m.find(num) != m.end()){
                auto [prev_idx, freq] = m[num];
                right[i] = right[prev_idx] + (long long)freq * (prev_idx - i);
            }
            m[num].first = i;
            ++(m[num].second);
            left[i] += right[i];
        }

        return left;
    }
};