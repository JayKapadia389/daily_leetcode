class Solution {
public:
    int maximumSwap(int num) {
        string numStr =
            to_string(num);  
        int n = numStr.size();
        int maxNum = num;  

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(numStr[i], numStr[j]);  
                maxNum = max(
                    maxNum,
                    stoi(numStr));  
                swap(numStr[i],
                     numStr[j]);  
            }
        }

        return maxNum;  
    }
};