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

    int height(TreeNode * root){
        if(root == NULL){
            return 0 ;
        }

        if(root->left ==  NULL && root->right == NULL){
            return 0 ;
        } 

        return 1 + max(height(root->left) , height(root->right)) ;


    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL){
            return true ;
        }

        int lh = height(root->left) ;
        int rh = height(root->right) ;

        if(lh != 0 || (lh == 0 && root->left != NULL)){
            lh++ ;
        }

        if(rh != 0 || (rh == 0 && root->right != NULL)){
            rh++ ;
        }

        bool isRootBalanced = (abs(lh - rh) <= 1) ;

        return (isBalanced(root->left) && isBalanced(root->left) && isRootBalanced) ;
        
    }
};