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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            ++n;
            temp = temp -> next;
        }

        if(n == 1) return NULL;

        int mid = n/2, idx = 0;
        temp = head;

        while(idx < (mid - 1)){
            ++idx;
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        return head;
    }
};