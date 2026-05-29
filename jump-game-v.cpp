class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int max_jumps = 1, n = arr.size();
        vector<pair<int, int>> height_idx;
        vector<int> dp(n, 1);

        for(int i = 0; i < n; ++i){
            height_idx.push_back({arr[i], i});
        }
        sort(height_idx.begin(), height_idx.end());

        for(auto [height, idx] : height_idx){
            int mx_option = 0;

            for(int i = 1; i <= d && (idx + i) < n; ++i){
                if(arr[idx + i] >= arr[idx]){
                    break;
                }
                mx_option = max(mx_option, dp[idx + i]);
            }

            for(int i = -1; i >= -d && (idx + i) >= 0; --i){
                if(arr[idx + i] >= arr[idx]){
                    break;
                }
                mx_option = max(mx_option, dp[idx + i]);
            }

            dp[idx] += mx_option;

            max_jumps = max(max_jumps, dp[idx]);
        }

        return max_jumps;
    }
};