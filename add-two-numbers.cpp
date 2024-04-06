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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = 0 , carry = 0 ;
        int add = 0 ;
        bool first = true ;
        ListNode * previous = NULL ;
        ListNode * head = NULL ;

        while(l1 != NULL || l2 != NULL || carry != 0){

            add = 0 ;

            if(l1){
                add += l1->val ;
            }
             if(l2){
                add += l2->val ;
            }
            add+= carry ;

            sum = add%10 ;

            //node
            ListNode * t = new ListNode(sum) ;

            if(first){

                head = t ;
                previous = t ;
            }
            else{
                previous->next = t;
                previous = t ;
            }

            carry = add/10 ;

            if(l1){
                l1 = l1->next ;
            }
            if(l2){
                l2 = l2->next ;
            }

            first =false ;

        }

        return head ;

    }
};