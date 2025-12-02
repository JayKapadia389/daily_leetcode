class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int ans = 0, mod = 1e9 + 7;
        map<int, int> m;

        for(auto &point : points){
            ++m[point[1]];
        }

        long long tops = 0;
        for(auto it : m){
            int num = it.second;

            if(num > 1){
                long long comb = (long)num * (num - 1) / 2;
                ans = (ans + (comb * tops) % mod) % mod;
                tops += comb;
            }
        }

        return ans;
    }
};

// Faster (Editorial) - Uses unordered_map instead of map. I thought unordered_map will be slower as it will take more time to iterate.
//
// class Solution {
// public:
//     int countTrapezoids(vector<vector<int>>& points) {
//         unordered_map<int, int> pointNum;
//         const int mod = 1e9 + 7;
//         long long ans = 0, sum = 0;
//         for (auto& point : points) {
//             pointNum[point[1]]++;
//         }
//         for (auto& [_, pNum] : pointNum) {
//             long long edge = (long long)pNum * (pNum - 1) / 2;
//             ans += edge * sum;
//             sum += edge;
//         }
//         return ans % mod;
//     }
// };