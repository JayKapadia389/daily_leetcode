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

    int core(TreeNode * root , int &ans ){

        if(root == NULL){
            return 0 ;
        }

        int lv = core(root->left , ans) ;
        int rv = core(root->right , ans) ;

        int sum = root->val;

        if(lv >= 0){
            sum += lv ;
        }
        if(rv >= 0){
            sum += rv ;
        }

        ans = max(ans , sum) ;

        if(lv < 0 && rv < 0){
            return root->val ;
        }

        return (root->val + max(lv , rv)) ;

    }

    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;

        core(root , ans) ;

        return ans ;
        
    }
};