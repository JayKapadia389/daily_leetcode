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

    unordered_map<int , bool> visited ;
    unordered_map<int , Node*> addr ; 

    void recc(Node* node , Node* clone){

        visited[clone->val] =1 ;

        for(auto ptr : node->neighbors){

            Node* temp;

            if(addr.find(ptr->val) == addr.end()){
                temp = new Node(ptr->val) ; 
                addr[ptr->val] = temp ; 
            }

            (clone->neighbors).push_back(addr[ptr->val]) ; 
        }

        for(int i = 0 ; i < (clone->neighbors).size() ; ++i){
            if(!visited[ 
                (clone->neighbors)[i]->val
             ]){
                recc((node->neighbors)[i] , (clone->neighbors)[i]) ; 
            }
        }

        return ;

    }

    Node* cloneGraph(Node* node) {
        
        if(node == NULL){
            return node ; 
        }

        Node* clone = new Node(node->val) ; 

        visited.clear() ; 
        addr.clear() ; 

        addr[1] = clone ; 
        recc(node , clone) ; 

        return clone ; 
    }
};