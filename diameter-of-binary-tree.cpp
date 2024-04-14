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

    int maxDepth(TreeNode * root){

        if(root == NULL){
            return 0 ;
        }
        else if (root->left == NULL && root->right == NULL){
            return 0 ;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right) ) ;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int lPath = 0 ; 

        if(root == NULL){
            return 0 ;
        }

        if(root->left == NULL && root->right == NULL){
            lPath = 0;
        }
        else if (root->left == NULL || root->right == NULL){
            lPath = 1 + maxDepth(root->left) + maxDepth(root->right) ;
        }
        else{
            lPath = 2 + maxDepth(root->left) + maxDepth(root->right) ;
        }

        return max(max(diameterOfBinaryTree(root->left) , diameterOfBinaryTree(root->right)) , lPath) ;
        
    }
};