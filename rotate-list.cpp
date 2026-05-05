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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;

        vector<int> v;
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp -> next;
            ++len;
        }

        int idx = 0;
        k = k % len;
        temp = head;
        while(temp != NULL){
            temp->val = v[(idx - k + len) % len];
            temp = temp -> next;
            ++idx;
        }

        return head;
    }
};