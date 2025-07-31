class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> universal_set, prev_set;

        for(int i = arr.size()-1; i>=0; --i){
            unordered_set<int> current_set;
            current_set.insert(arr[i]);

            for(auto it : prev_set){
                current_set.insert(it | arr[i]);
            }
            universal_set.insert(current_set.begin(), current_set.end());

            prev_set = current_set;
        }

        return universal_set.size();
    }
};