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

    // Encodes a tree to a single string.

    string str = "" ;

    string serialize(TreeNode* root) {

        if(str != "" && str[str.length() -1 ] == ')'){
            str = "" ;
        }

        if(root == NULL){
            return str;
        }

        str += to_string(root->val) ;

        str+= "(";
        serialize(root->left);
        str+= ")(";
        serialize(root->right);
        str+=")";

        return str ;
        
    }

    string data_ ;

    TreeNode * deserializeCore(){

        static int i = 0 ;

        if(data_ == ""){
            return NULL ;
        }

        if(data_[i] == ')'){
            return NULL ;
        }

        int j = i+1 ;
        int c = 1 ;
        while(true){
            if(data_[j] != '('){
                c++ ;
                j++ ;
            }
            else{
                break ;
            }
        }

        int num = stoi(data_.substr(i , c)) ;

        TreeNode * temp = new TreeNode(num) ;

        i = j+1 ;

        temp->left = deserializeCore() ;

        i+=2 ;

        temp->right = deserializeCore() ;

        i+=1 ;

        if(i == (data_.length())){
            i = 0 ;
        }

        return temp ;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data ) {

        data_ = data ;

        return deserializeCore() ;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));