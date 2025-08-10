class Solution {
public:
    int len;

    bool power_of_two(int num){
        return !(num&(num-1));
    }

    bool recc(vector<int>& digits, vector<bool>& used, int base){
        bool completed = 1;
        for(auto b : used){
            if(b == 0){
                completed = 0;
            }
        }
        if(completed){
            return power_of_two(base);
        }

        for(int i = 0; i < len; ++i){
            if(!used[i]){
                used[i] = 1;
                int next = base*10 + digits[i];
                if(recc(digits, used, next)){
                    return true;
                }
                used[i] = 0;
            }
        }
        return false;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> digits;

        while(n != 0){
            digits.push_back(n%10);
            n /= 10;
        }

        len = digits.size();
        vector<bool> used(len,0);

        for(int i = 0; i < len; ++i){
            if(digits[i] != 0){
                used[i] = 1;
                if(recc(digits, used, digits[i])){
                    return true;
                }
                used[i] = 0;
            }
        }
        return false;
    }
};