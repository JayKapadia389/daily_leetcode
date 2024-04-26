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

    int core(TreeNode * root , int k , int &ans ){

        if(root->left == NULL && root->right == NULL){
            k-- ;

            if(k == 0){

                
                ans = root->val ;
            }
                return k;
        }

        if(root->left != NULL){
            k = core(root->left , k , ans) ;

            if(k == 0){
                return k;
            }
        }

        k-- ;

        if(k == 0){
            ans = root->val  ;

            return k;
        }

        if(root->right != NULL)
        k = core(root->right , k , ans) ;

        return k ;

    }

    int kthSmallest(TreeNode* root, int k) {

        int ans ; 

        core(root , k , ans) ;

        return ans ;
        
    }
};