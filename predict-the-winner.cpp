#define PII pair<int, int>

class Solution {
private:
PII recc(vector<int>& nums, int l, int r, bool turn) {
    if(l > r){
        return {0, 0};
    }

    PII left = recc(nums, l + 1, r, !turn);
    PII right = recc(nums, l, r - 1, !turn);
    if(!turn) { // p 1
        left.first += nums[l];
        right.first += nums[r];
        int left_diff = left.first - left.second;
        int right_diff = right.first - right.second;
        return (left_diff >= right_diff)? left : right;
    }
    else{ // p 2
        left.second += nums[l];
        right.second += nums[r];
        int left_diff = left.second - left.first;
        int right_diff = right.second - right.first;
        return (left_diff >= right_diff)? left : right;
    }
}

public:
    bool predictTheWinner(vector<int>& nums) {
        PII final = recc(nums, 0, nums.size() - 1, 0);
        return final.first >= final.second;
    }
};