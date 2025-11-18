class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();

        while(i < n-1){
            if(bits[i] == 0) 
                i += 1;
            else
                i += 2;
        }

        return i != n;
    }
};