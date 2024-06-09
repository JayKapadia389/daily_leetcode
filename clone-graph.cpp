/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        map<int , Node*> m ;

        queue<Node*> q ;

        if(node == NULL){
            return node ;
        }

        Node * head = new Node(node->val) ; 

        m[node->val] = head ;

        q.push(node) ;

        while(!q.empty()){

            Node * originalTemp = q.front() ;
            Node * duplicateTemp = m[originalTemp->val] ;

            q.pop() ;

            vector<Node*> originalNeighbors = originalTemp->neighbors;

            for(int i = 0 ; i < originalNeighbors.size() ; i++){

                Node* t ;
                if(m[originalNeighbors[i]->val] != 0){
                    t = m[originalNeighbors[i]->val] ;
                }

                else{

                t = new Node(originalNeighbors[i]->val) ;

                m[originalNeighbors[i]->val] = t ;

                q.push(originalNeighbors[i]) ;
                }

                (duplicateTemp->neighbors).push_back(t) ;

            }

        }

        return head ;
        
    }
};