class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        sort(towers.begin(), towers.end());
        int q = INT_MIN;
        vector<int> ans = {-1, -1};

        for(auto tower : towers){
            if(abs(tower[0] - center[0]) + abs(tower[1] - center[1]) <= radius){
                 if(tower[2] > q){
                     q = tower[2];
                     ans = {tower[0], tower[1]};
                 }   
            }
        }

        return ans;
    }
};