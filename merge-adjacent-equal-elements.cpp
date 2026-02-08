// contest
// Solution 1:
// doubly linked-list
// O(n) time - 5n 
// o(n) space - 4n
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> nums_long(n);
        vector<int> prev(n);
        vector<int> next(n);

        for(int i = 0; i < n; ++i){
            nums_long[i] = nums[i];
            prev[i] = i-1;
            next[i] = i+1;
        }
        next[n-1] = -1;

        int curr = 0, prev_curr = 0;
        while(curr != -1){
            // left
            if(prev[curr] != -1 && nums_long[prev[curr]] == nums_long[curr]){
                nums_long[curr] += nums_long[prev[curr]];
                int i = prev[prev[curr]];
                if(i != -1) next[i] = curr;
                prev[curr] = i;
                continue;
            }

            //right
            if(next[curr] != -1 && nums_long[next[curr]] == nums_long[curr]){
                nums_long[curr] += nums_long[next[curr]];
                int i = next[next[curr]];
                if(i != -1) prev[i] = curr;;
                next[curr] = i;
                continue;
            }

            prev_curr = curr;
            curr = next[curr];
        }

        vector<long long> ans;
        while(prev_curr != -1){
              ans.push_back(nums_long[prev_curr]);
              prev_curr = prev[prev_curr];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Solution 2:
// stack 
// O(n) time - 3n
// O(n) space - 2n
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        stack<long long> st;

        // 2n
        for(int i = 0; i < n; ++i){
            long long curr = nums[i];
            while(!st.empty() && (st.top() == curr)){
                curr += st.top();
                st.pop();
            }
            st.push(curr);
        }

        // n
        vector<long long> ans(st.size());
        for(int i = st.size() - 1; i >= 0; --i){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

// Solution 3 (best):
// stack
// O(n) - 2n
// O(n) space - n
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans;

        // 2n
        for(int i = 0; i < n; ++i){
            long long curr = nums[i];
            while(!ans.empty() && (ans.back() == curr)){
                curr *= 2;
                ans.pop_back();
            }
            ans.push_back(curr);
        }

        return ans;
    }
};