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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL){
            return NULL ;
        }
        if(head->next == NULL){
            return head ;
        }

        ListNode * f = NULL ;
        ListNode * s = head ;
        ListNode * t = head->next ;

        do{

            s->next = f ;

            f = s;
            s = t ;

            if(t!=NULL){
                t = t->next ;
            }

        }while(s != NULL) ;

        return f ;

    }
};