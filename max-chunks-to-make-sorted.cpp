class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        stack<int> monotonicStack;
        for (int i = 0; i < n; i++) {
            if (monotonicStack.empty() || arr[i] > monotonicStack.top()) {
                monotonicStack.push(arr[i]);
            }
            else {
                int maxElement = monotonicStack.top();
                while (!monotonicStack.empty() &&
                    arr[i] < monotonicStack.top()) {
                    monotonicStack.pop();
                }
                monotonicStack.push(maxElement);
            }
        }
        return monotonicStack.size();
    }
};