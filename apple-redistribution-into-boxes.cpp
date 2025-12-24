class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0, cnt = 0;

        for(auto num : apple){
            sum += num;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        while(sum > 0){
            sum -= capacity[cnt];
            ++cnt;
        }

        return cnt;
    }
};