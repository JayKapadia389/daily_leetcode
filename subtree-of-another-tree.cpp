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

    bool isEqual(TreeNode * r1 , TreeNode * r2){

        if(r1 == NULL && r2 == NULL){
            return true ;
        }
        else if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){
            return false ;
        }

        return ( r1->val == r2->val && isEqual(r1->left , r2->left) && isEqual(r1->right , r2->right)  ) ;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == NULL){
            return false ;
        }

        else{

            if(isEqual(root , subRoot))
            {
                return true ;
            }

            else{
                if(isSubtree(root->left , subRoot)){
                    return true ;
                }
                else if(isSubtree(root->right , subRoot)) {
                    return true ;
                }
                else{
                    return false ;
                }
            }
            
        }
        
    }
};