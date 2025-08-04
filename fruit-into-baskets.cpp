class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 1;
        int l = 0, r = 0;
        pair<int, int> fruit1, fruit2;
        fruit1.first = fruits[0];
        fruit1.second = 1;
        fruit2.first = -1;
        fruit2.second = 0;
        ++r;

        while(r < fruits.size()){
            if(fruits[r] == fruit1.first || fruits[r] == fruit2.first || fruit2.first == -1){
                ans = max(ans, r-l+1);
                if(fruits[r] == fruit1.first){
                    ++fruit1.second;
                }
                else if(fruits[r] == fruit2.first){
                    ++fruit2.second;
                }
                else if(fruit2.first == -1){
                    fruit2.first = fruits[r];
                    fruit2.second = 1;
                }
            }
            else{
                while(fruit1.second != 0 && fruit2.second != 0){
                    if(fruits[l] == fruit1.first){
                        --fruit1.second;
                    }
                    else{
                        --fruit2.second;
                    }
                    ++l;
                }
                if(fruit1.second == 0){
                    fruit1.first = fruits[r];
                    fruit1.second = 1;
                }
                else{
                    fruit2.first = fruits[r];
                    fruit2.second = 1;
                }
            }
            ++r;
        }

        return ans;
    }
};