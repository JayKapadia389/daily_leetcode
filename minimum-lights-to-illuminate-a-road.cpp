class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<bool> visible(n, 0);
        vector<int> blocks;

        int v = 0;
        for(int i = 0; i < n; ++i){
            if(v != 0){
                visible[i] = 1;
                --v;
            }

            v = max(v, lights[i]);

            if(v != 0){
                visible[i] = 1;
            }
        }
        
        v = 0;
        for(int i = n - 1; i >= 0; --i){
            if(v != 0){
                visible[i] = 1;
                --v;
            }

            v = max(v, lights[i]);

            if(v != 0){
                visible[i] = 1;
            }
        }

        int streak = 0;
        for(int i = 0; i < n; ++i){
            if(!visible[i]){
                ++streak;
            }
            else if(streak != 0){
                blocks.push_back(streak);
                streak = 0;
            }
        }

        if(streak != 0){
            blocks.push_back(streak);
        }
        
        int ans = 0;
        for(auto block : blocks){
            int bulb = ceil(block / 3.0);
            ans += bulb;
        }
        return ans;
    }
};