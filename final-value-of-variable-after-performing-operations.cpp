class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        
        for(auto op : operations)
            x = (op[1] == '+') ? x+1 : x-1;

        return x;
    }
};