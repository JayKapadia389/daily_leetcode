class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0, x = 0, y = 0, dir = 0;
        set<vector<int>> s(obstacles.begin(), obstacles.end());

        for(auto command : commands){
            if(command == -1){
                dir = ((dir + 1) + 4) % 4;
            }
            else if(command == -2){
                dir = ((dir - 1) + 4) % 4;
            }
            else{
                for(int i = 0; i < command; ++i){
                    int new_x = x;
                    int new_y = y;

                    if(dir == 0){
                        ++new_y; 
                    }
                    else if(dir == 1){
                        ++new_x; 
                    }
                    else if(dir == 2){
                        --new_y; 
                    }
                    else {
                        --new_x; 
                    }

                    if(!s.contains({new_x, new_y})){
                        x = new_x;
                        y = new_y;
                    }

                    ans = max(ans, x*x + y*y);
                }
            }
        }

        return ans;
    }
};