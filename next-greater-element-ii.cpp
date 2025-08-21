class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> st;
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; ++i){
            int curr = nums[i];

            while(!st.empty() && st.top().first < curr){
                pair p = st.top();
                st.pop();
                ans[p.second] = curr;
            }
            st.push({curr, i});
        }

        // second pass
        for(int i = 0; i < n; ++i){
            int curr = nums[i];
            while(!st.empty() && st.top().first < curr){
                pair p = st.top();
                st.pop();
                ans[p.second] = curr;
            }
        }

        while(!st.empty()){
            ans[st.top().second] = -1;
            st.pop();
        }

        return ans;
    }
};