string directions[] = {"East", "North", "West", "South"};

class Robot {
private:
int x = 0, y = 0;
int dir = 0;
int width, height, mod;
bool started = 0;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        mod = 2 * (width + height) - 4;
    }
    
    void step(int num) {
        num = num % mod;
        if(num == 0 && !started){
            dir = 3;
        }

        while(num != 0){
            int new_x = x;
            int new_y = y;

            if(dir == 0){
                ++new_x;
            }
            else if(dir == 1){
                ++new_y;
            }
            else if(dir == 2){
                --new_x;
            }
            else{
                --new_y;
            }

            if(new_x >= 0 && new_x < width && new_y >= 0 && new_y < height){
                --num;
                x = new_x;
                y = new_y;
            }
            else{
                dir = (dir + 1) % 4;
            }
        }

        started = 1;
    }
    
    vector<int> getPos() {
        return vector<int>({x, y});
    }
    
    string getDir() {
        return directions[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */