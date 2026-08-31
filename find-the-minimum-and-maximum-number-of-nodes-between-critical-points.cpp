class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idxs;
        ListNode* curr = head->next;
        int prev_val = head->val;
        int idx = 1;
        vector<int> ans = {INT_MAX, -1};
        int first_c = -1;
        int last_c = -1;

        while((curr->next) != NULL) {
            int next_val = curr->next->val;
            int curr_val = curr->val;

            bool is_local_maxima = (prev_val < curr_val) && (next_val < curr_val);
            bool is_local_minima = (prev_val > curr_val) && (next_val > curr_val);

            if(is_local_maxima || is_local_minima){
                if(first_c == -1){
                    first_c = idx;
                }
                else{
                    ans[0] = min(ans[0], idx - last_c);
                    ans[1] = idx - first_c;
                }
                last_c = idx;
            }

            ++idx;
            curr = curr->next;
            prev_val = curr_val;
        }

        if(ans[1] == -1){
            ans[0] = -1;
        }

        return ans;
    }
};