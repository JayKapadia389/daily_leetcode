class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mn = INT_MAX, n = arr.size();
        vector<vector<int>> ans;
        ans.reserve(n);

        for(int i = 0; i < n - 1; ++i){
            int diff = arr[i+1] - arr[i];

            if(diff == mn){
                ans.push_back({arr[i], arr[i+1]});
            }
            else if(diff < mn){
                mn = diff;
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};