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
    int getDecimalValue(ListNode* head) {

        vector<bool> bits(30) ; 
        int i = 0 ; 

        while(head != NULL){
            bits[i] = head->val ; 

            head = head->next ; 
            ++i ; 
        } 

        int k = 1 , ans = 0 ;

        for(int j = i-1 ; j >= 0 ; --j){
            ans += (bits[j] * k) ;  
            k = k << 1 ; 
        }

        return ans ;
        
    }
};