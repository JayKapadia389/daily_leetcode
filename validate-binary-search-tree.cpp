/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool core(TreeNode * root , long int mn , long int mx){

        if(root == NULL){
            return true ;
        }

        if((root->val > mn) && (root->val < mx)){

            return (core(root->left , mn , root->val) && core(root->right , root->val , mx)) ;

        }
        else{
            return false ;
        }

    }

    bool isValidBST(TreeNode* root) {

        return core(root , -99999999999 , 99999999999) ;
        
    }
};