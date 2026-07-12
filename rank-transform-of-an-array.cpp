class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;

        vector<int> copy = arr;
        unordered_map<int, int> ranks;
        int r = 1;

        sort(copy.begin(), copy.end());

        ranks[copy[0]] = 1;
        for(int i = 1; i < copy.size(); ++i) {
            if(copy[i] != copy[i - 1]){
                ++r;
            }
            ranks[copy[i]] = r;
        }

        for(auto& num : arr) {
            num = ranks[num];
        }

        return arr;
    }
};