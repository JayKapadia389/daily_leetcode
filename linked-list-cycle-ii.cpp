/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;

        ListNode *slow = head , *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }

        if(fast != slow){
            return NULL;
        }

        fast = head;

        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};