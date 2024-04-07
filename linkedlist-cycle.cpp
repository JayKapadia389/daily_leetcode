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
    bool hasCycle(ListNode *head) {
        
        ListNode * f = head ;
        ListNode * s = head ;

        bool flag = false ;

        while(f != NULL){

            f = f->next ;

            if(flag){
                s = s->next ;
            }

            if(f == s){
                return true  ;
            }

            flag = !flag ;
        }

        return false ;
        
    }
};