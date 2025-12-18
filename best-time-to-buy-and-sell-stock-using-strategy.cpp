class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long sum = 0;
        int n = prices.size();

        for(int i = 0; i < n; ++i){
            sum += (prices[i] * strategy[i]);
        }

        // create first window
        long long change = 0;
        for(int i = 0; i < k/2; ++i){
            change += (prices[i] * (0 - strategy[i]));
        }

        for(int i = k/2; i < k; ++i){
            change += (prices[i] * (1 - strategy[i]));
        }

        long long max_change = change;

        // roll the window and maximise change
        for(int i = k; i < n; ++i){
            int a = i - k, b = a + k/2, c = i;
            change += (prices[a] * strategy[a]) ;
            change += (prices[c] * (1 - strategy[c])) ;
            change += (-prices[b]) ;
            max_change = max(max_change, change);
        }
        sum = max(sum, sum + max_change);
        return sum;
    }
};