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

    bool isLen(ListNode * curr , int k){

        int c= 0;

        while(curr != NULL && c <= k){
            c++ ;
            curr = curr->next ;
        }

        if(c >= k){
            return true ;
        }
        return false ;
    }

    void changePrev(ListNode * temp , ListNode *  &prev , int k){

        prev = temp ;

        for(int i = 1 ; i< k ; i++){
            prev = prev->next ;
        }
        return ;

    }

    ListNode * rev(ListNode * &curr , int k){

        ListNode * first = NULL ;
        ListNode * second = curr ;
        ListNode * third = curr->next  ;

        for(int i = 0 ; i < k ; i++){
            second->next = first ;

            first = second;
            second = third;

            if(third != NULL){
            third  = third->next ;
            }

        }

        curr = second ;
        return first ;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode * newHead = head ;
        ListNode * curr = head ;
        ListNode * temp = NULL ;
        ListNode * prev = NULL ;

        while(true){

            if(!isLen(curr , k)){
                if(prev == NULL){
                    return head ;
                }
                else{
                    prev->next = curr ;
                    return newHead;
                }
            }

            else{

                temp = rev(curr , k) ;

                if(prev == NULL){
                    newHead = temp ;
                }
                else{
                    prev->next = temp ;
                }

                changePrev(temp, prev ,k) ;

            }
        }
        
    }
};