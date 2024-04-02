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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL || list2 == NULL){

            if(list1 == NULL && list2 == NULL){
                return NULL ;
            }

            return (list1 == NULL)? list2 : list1 ;
        }

        ListNode * head = NULL ;
        ListNode * l = NULL ;

        if(list1->val == list2->val){
            head = list1 ;

            if(head->next == NULL){
                head->next = list2 ;
                return head ;
            }
            else{
                l = head ;
                list1 = head->next ;
            }
        }
        else if(list1->val < list2->val){
            head = list1 ;

            if(head->next == NULL){
                head->next = list2 ;
                return head ;
            }
            else{
                l = head ;
                list1 = head->next ;
            }
        }
        else{
            head = list2 ;

            if(head->next == NULL){
                head->next = list1 ;
                return head ;
            }
            else{
                l = head ;
                list2 = head->next ;
            }
        }

        while(true){

            if(list1->val <= list2->val){

                l->next = list1 ;

                l = l->next ;

                if(list1->next == NULL){
                    list1->next = list2 ;
                    return head ;
                }
                else{
                    list1 = list1->next ;
                }

            }
            else{

                l->next = list2 ;

                l = l->next ;

                if(list2->next == NULL){
                    list2->next = list1 ;
                    return head ;
                }
                else{
                    list2 = list2->next ;
                }

            }
        }
        
    }
};