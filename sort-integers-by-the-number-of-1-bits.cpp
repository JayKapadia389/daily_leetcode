class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> num_bits;

        for(auto num : arr){
            num_bits.push_back({__builtin_popcount(num), num});
        }

        sort(num_bits.begin(), num_bits.end());

        for(int i = 0; i < n; ++i){
            arr[i] = num_bits[i].second;
        }

        return arr;
    }
};