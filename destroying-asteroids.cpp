class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long mass_long = mass;
        for(auto m : asteroids){
            if(m > mass_long){
                return false;
            }

            mass_long += m;
        }

        return true;
    }
};