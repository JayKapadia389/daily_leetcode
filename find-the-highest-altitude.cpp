class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0, curr = 0;

        for(auto delta : gain){
            curr += delta;
            highest = max(highest, curr);
        }

        return highest;
    }
};