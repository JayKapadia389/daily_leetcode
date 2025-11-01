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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set;

        for(auto num : nums){
            set.insert(num);
        }

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while(curr != NULL){
            if(set.find(curr->val) == set.end()){
                prev = prev->next;
            }
            else{
                prev->next = curr->next;
            }
            curr = prev->next;
        }

        return (&dummy)->next;
    }
};