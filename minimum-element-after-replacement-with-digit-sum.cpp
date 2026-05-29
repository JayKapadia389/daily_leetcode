class Solution {
private:
int sum_of_digits(int num){
    int sum = 0;

    while(num != 0){
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for(auto num : nums){
            mn = min(mn, sum_of_digits(num));
        }

        return mn;
    }
};