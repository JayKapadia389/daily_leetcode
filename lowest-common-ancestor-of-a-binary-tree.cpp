/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    int matchesFound(TreeNode * root , TreeNode* p, TreeNode* q , TreeNode * &LCA){

        if(root == NULL){
            return 0 ;
        }

        // int ret = 0 ;

        int lc = matchesFound(root->left , p , q , LCA ) ;
        int rc = matchesFound(root->right , p , q , LCA ) ;

        if(lc == 2 || rc == 2){
            return 2 ;
        }

        if(lc + rc == 2){
            LCA = root ;
            return 2 ;
        }

        else{

            if(root == p || root == q ){ //
                
                if(lc + rc + 1 == 2){
                    LCA = root ;
                    return 2 ;
                }
                else{
                    return 1 ;
                }

            }
            else{
                return (lc + rc) ;
            }

        }

        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode * LCA = NULL ;

        matchesFound( root ,  p,  q , LCA) ; 

        return LCA ;
        
    }
};