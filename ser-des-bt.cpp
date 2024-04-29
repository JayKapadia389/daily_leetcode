/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string parse(string s , int &i){
        string res = "" ;

        while(s[i] != ','){
            res += s[i] ;
            i++ ;
        }

        return res ;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        queue<TreeNode *> q ;
        string s = "" ;

        if(root == NULL){
            return s ;
        }

        q.push(root) ;
        q.push(NULL) ;

        TreeNode * dummy = new TreeNode(1001) ;

        while(q.size() > 1){

            TreeNode * temp = q.front() ;
            q.pop() ;

            if(temp == NULL){
                q.push(NULL) ;
            }
            else if(temp->val == 1001){
                s += "n," ;
            }

            else{

                s += to_string(temp->val) + "," ;

                if(temp->left == NULL){
                    q.push(dummy) ;
                }
                else{
                    q.push(temp->left) ;
                }

                if(temp->right == NULL){
                    q.push(dummy) ;
                }
                else{
                    q.push(temp->right) ;
                }

            }
        }

        return s ;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data == ""){
            return NULL ;
        }

        queue<TreeNode * > q;

        int i = 0 ;
        string tempStr = parse(data , i) ;

        int integer = stoi(tempStr) ;
        TreeNode * root = new TreeNode(integer) ;
        TreeNode * temp = new TreeNode(0) ;

        q.push(temp) ;

        while(!q.empty()){

            temp = q.front() ;
            q.pop() ;

            i++ ;
            string sl = parse(data , i) ;
            // cout << sl << " ";
            i++ ;
            string sr = parse(data , i) ;
            // cout << sr << endl;


            TreeNode * left ;
            TreeNode * right ;

            if(sl == "n"){
                left = NULL ;
            }
            else{
                left = new TreeNode(stoi(sl)) ;
            }

            if(sr == "n"){
                right = NULL ;
            }
            else{
                right = new TreeNode(stoi(sr)) ;
            }

            // cout << left->val << " " << right->val << endl ;
            temp->left = left ;
            temp->right = right ;

            if(left != NULL){
                q.push(left) ;
            }
            if(right != NULL){
                q.push(right) ;
            }

        }

        return root ;


        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));