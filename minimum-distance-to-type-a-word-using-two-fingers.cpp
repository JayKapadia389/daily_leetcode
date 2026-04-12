int OFFSET = 1;

class Solution {
private:
int recc(int idx, int x1, int y1, int x2, int y2, vector<vector<vector<vector<vector<int>>>>>& dp, const int& n, unordered_map<char, pair<int, int>>& m, const string& word){
    if(idx == n){
        return 0;
    }

    if(dp[idx][x1 + OFFSET][y1 + OFFSET][x2 + OFFSET][y2 + OFFSET] != -1){
        return dp[idx][x1 + OFFSET][y1 + OFFSET][x2 + OFFSET][y2 + OFFSET];
    }

    int first_finger = 0, second_finger = 0;
    int x_target = m[word[idx]].first;
    int y_target = m[word[idx]].second;

    if(x1 != -1){
        first_finger += (abs(x_target - x1) + abs(y_target - y1));
    }
    first_finger += recc(idx + 1, x_target, y_target, x2, y2, dp, n, m, word);

    if(x2 != -1){
        second_finger += (abs(x_target - x2) + abs(y_target - y2));
    }
    second_finger += recc(idx + 1, x1, y1, x_target, y_target, dp, n, m, word);

    return dp[idx][x1 + OFFSET][y1 + OFFSET][x2 + OFFSET][y2 + OFFSET] = min(first_finger, second_finger);
}

public:
    int minimumDistance(string word) {
        unordered_map<char, pair<int, int>> m;
        int n = word.size();
        vector<vector<vector<vector<vector<int>>>>> dp(n, vector<vector<vector<vector<int>>>>(6, vector<vector<vector<int>>>(7, vector<vector<int>>(6, vector<int>(7, -1)))));

        for(int i = 0; i < 26; ++i){
            m[static_cast<char>('A' + i)] = {i / 6, i % 6};
        }

        return recc(0, -1, -1, -1, -1, dp, n, m, word);
    }
};