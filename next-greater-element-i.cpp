class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> m;

        for(int n : nums2){
            while(!st.empty() && st.top() < n){
                m[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }

        vector<int> ans;
        for(int q : nums1){
            ans.push_back(m.count(q) ? m[q] : -1);
        }

        return ans;
    }
};