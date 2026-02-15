// contest
// not upsolved
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> switches(101, 0);

        for(int i = 0; i < bulbs.size(); ++i){
            int bulb = bulbs[i];
            switches[bulb] = !switches[bulb];
        }

        vector<int> ans;
        for(int i = 1; i <= 100; ++i){
            if(switches[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};