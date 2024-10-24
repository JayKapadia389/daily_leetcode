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

    bool core(TreeNode * curr1 , TreeNode * curr2){

        TreeNode * firstLeft = curr1->left ;
        TreeNode * firstRight = curr1->right ;
        TreeNode * secondLeft = curr2->left ;
        TreeNode * secondRight = curr2->right ;

        if(firstLeft == NULL && firstRight == NULL && secondLeft == NULL && secondRight == NULL ){
            return true ;
        }

        else if(((firstLeft == NULL && firstRight != NULL) || (firstLeft != NULL && firstRight == NULL)) && 
                ((secondLeft == NULL && secondRight != NULL) || (secondLeft != NULL && secondRight == NULL))){

                    TreeNode * firstNotNULL = (firstLeft == NULL) ? firstRight : firstLeft;
                    TreeNode * secondNotNULL = (secondLeft == NULL) ? secondRight : secondLeft;

                    if(firstNotNULL->val == secondNotNULL->val ){
                        return core(firstNotNULL , secondNotNULL) ;
                    }

                    else{
                        return false ;
                    }


                }

                else if(firstLeft && firstRight && secondLeft && secondRight){

                    if(
                        //same pairs
                        ((firstLeft->val == secondLeft->val) && (firstRight->val == secondRight->val)) ||
                        ((firstLeft->val == secondRight->val) && (firstRight->val == secondLeft->val))
        
                    ){

                        if(
                            //not-mirrored
                            firstLeft->val == secondLeft->val
                        )
                        {
                            //call ordered
                            return core(firstLeft,secondLeft) && core(firstRight,secondRight) ;
                        }
                        else{
                            return core(firstLeft,secondRight) && core(firstRight,secondLeft) ;
                        }

                    }
                    else{
                        return false ;
                    }

                }

                else{
                    return false ;
                }

    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        if(root1 == NULL && root2 == NULL){
            return true ;
        }
        if(root1 == NULL || root2 == NULL){
            return false ;
        }

        if(root1->val != root2->val){
            return false ;
        }

        return core(root1 , root2) ;
        
    }
};