class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> dp(robotCount + 1,
                                     vector<long long>(factoryCount + 1, 0));

        for (int i = 0; i < robotCount; i++)
            dp[i][factoryCount] = 1e12;  

        for (int i = robotCount - 1; i >= 0; i--) {
            for (int j = factoryCount - 1; j >= 0; j--) {
                long long assign =
                    abs(robot[i] - factoryPositions[j]) + dp[i + 1][j + 1];

                long long skip = dp[i][j + 1];

                dp[i][j] = min(assign, skip);  
            }
        }
        return dp[0][0];
    }
};