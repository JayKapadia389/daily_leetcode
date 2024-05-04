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

    void core(TreeNode * root , int max , int &count){

        if(root == NULL){
            return ;
        }

        if(root->val >= max){
            //good node
            count++ ;
            core(root->left , root->val , count) ;
            core(root->right , root->val , count) ;
        }
        else{
            core(root->left , max , count) ;
            core(root->right , max , count) ;
        }

        return ;
    }

    int goodNodes(TreeNode* root) {

        int count = 0 ;

        core(root , INT_MIN , count  ) ;

        return count ;

    }
};