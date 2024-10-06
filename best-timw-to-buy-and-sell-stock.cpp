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

    bool isBal = true ;

    int getHeight(TreeNode * temp){

        if(temp->left == NULL && temp->right == NULL){
            return 0 ;
        }

        int lh =0, rh =0  ;

        if(temp->left != NULL){
            lh = 1+getHeight(temp->left);
        }
        if(temp->right != NULL){
            rh = 1+getHeight(temp->right);
        }

        if( abs(lh - rh) > 1){
            isBal = false ; 
        }

        return max(lh , rh) ;

    }

    bool isBalanced(TreeNode* root) {

        if(root == NULL){
            return true ;
        }

        getHeight(root) ;

        return isBal ;
        
    }
};