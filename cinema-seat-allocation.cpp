#define PII pair<int, int>

class Solution {
private:
bool block(int block, int row, unordered_map<int, unordered_map<int, bool>>& reserved) {
    int i = (block == 1) ? 2 : ((block == 2)? 4 : 6);

    for(int j = 0; j < 4; ++j){
        if(reserved.find(row) != reserved.end() && reserved[row].find(i + j) != reserved[row].end()){
            return false;
        }
    }

    return true;
}

public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<int> rows_affected;
        unordered_map<int, unordered_map<int, bool>> reserved;

        for(auto rs : reservedSeats) {
            rows_affected.insert(rs[0]);
            reserved[rs[0]][rs[1]] = true;
        }

        int n_rows_affected = rows_affected.size();
        int ans = (n - n_rows_affected) * 2;

        for(auto row : rows_affected) {
            if(block(1, row, reserved)){
                ++ans;
                if(block(3, row, reserved)){
                    ++ans;
                }
            }
            else{
                if(block(2, row, reserved)){
                    ++ans;
                }
                else{
                    if(block(3, row, reserved)){
                        ++ans;
                    }
                }
            }
        }

        return ans;
    }
};