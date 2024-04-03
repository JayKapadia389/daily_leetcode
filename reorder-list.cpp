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

    void rev(ListNode * &head){
        if(head == NULL || head->next == NULL){
            return ;
        }

        ListNode * f = NULL ;
        ListNode * s = head ;
        ListNode * t = head->next ;

        while(s != NULL){

            s->next = f ;

            f = s ;
            s = t ;
            if(t != NULL){
                t = t->next ;
            }
        }

        head = f ;
        return ;

    }

    void reorderList(ListNode* head) {

        int len = 0 ;

        ListNode* temp = head ;

        while(temp != NULL){
            len++ ;
            temp = temp->next ;
        }

        if(len == 0 || len == 1 || len == 2){
            return ;
        }

        int h ;

        if(len%2 == 0){
            h = len/2 ;
        }
        else{
            h = len/2 + 1 ;
        }

        temp = head ;

        for(int i = 1 ; i < h ; i++){
            temp = temp->next ;
        }

        ListNode * list2 = temp->next ;
        temp->next = NULL ;

        rev(list2) ;

        ListNode * a1 = head ;
        ListNode * a2 = head ;

        ListNode * b1 = list2 ;
        ListNode * b2 = list2 ;

        while(true){

            a2 = a1->next ;
            a1->next  = b1 ;

            if(a2 == NULL){
                break ;
            }
            a1=a2 ;

            b2 = b1->next ;
            b1->next = a2 ;

            if(b2 == NULL){
                break ;
            }
            b1 = b2 ;

        }

        return ;
        
    }
};