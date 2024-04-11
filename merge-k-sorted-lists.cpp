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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0){
            return NULL ;
        }

        ListNode * head = NULL ;
        ListNode * prev = NULL ;
        ListNode * ptr = new ListNode(INT_MAX) ;
        int idx = -1 ;

        while(true){

            ptr = new ListNode(INT_MAX) ;
            idx = -1 ;

            for(int i = 0 ; i < lists.size() ; i++){

                    if(lists[i] != NULL && lists[i]->val < ptr->val){
                        idx = i ;
                        ptr = lists[i] ;
                }

            }

            if(idx == -1){
                return head ;
            }
            else{

                if(prev == NULL){
                    prev = ptr ;
                    head = ptr ;
                }
                else{

                    prev->next = ptr ;
                    prev = ptr ;

                }

                lists[idx] = lists[idx]->next ;
            }

        }
        
    }
};