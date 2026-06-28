class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; ++i){
            if(i == 0){
                arr[i] = 1;
            }
            else{
                arr[i] = min(arr[i], arr[i - 1] + 1);
            }
        }

        return arr[n-1];
    }
};