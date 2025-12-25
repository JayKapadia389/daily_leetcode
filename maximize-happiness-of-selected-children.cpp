class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0, i = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());

        while(k != 0){
            int happiness_value = happiness[i] - i;

            if(happiness_value <= 0) break;

            ans += happiness_value;
            ++i;
            --k;
        }

        return ans;
    }
};