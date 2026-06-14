/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> elements;
        ListNode* curr = head;
        int ans = INT_MIN;
        int n;

        while(curr != NULL) {
            elements.push_back(curr -> val);
            curr = curr -> next;
        }

        n = elements.size();

        for(int i = 0; i <= (n/2) - 1; ++i){
            ans = max(ans, elements[i] + elements[n - i - 1]);
        }

        return ans;
    }
};