/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        map<Node * , int> m ;
        int size = 0 ;

        Node * temp = head ;
        
        while(temp != NULL){
            m[temp] = size ;
            size++ ;
            temp = temp->next ;
        }

        vector<int> toNode(size) ;

        temp = head ;

        for(int i = 0 ; i < size ; i++){

            if(temp->random == NULL){
                toNode[i] = -1 ;
            }
            else{
                toNode[i] = m[temp->random] ;
            }

            temp = temp->next ;
        }

        Node * prev = NULL ;
        vector<Node *> add(size) ;
        Node * newHead = NULL ;

        Node * t = NULL ;

        for(int i = 0  ; i < size  ; i++){

            t = new Node(head->val) ;
            add[i] = t ;

            if(i == 0){
                newHead = t ;
                prev = newHead ;
            }
            else{
                prev->next = t ;
                prev = prev->next ;
            }

            head = head->next ;

        }

        temp = newHead ;

        for(int i = 0 ;i < size ; i++){

            if(toNode[i] == -1){
                temp->random = NULL ;
            }
            else{
                temp->random = add[toNode[i]] ;
            }

            temp = temp->next ;

        }

        return newHead ;

    }
};