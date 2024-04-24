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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans ;

        if(root == NULL){
            return ans ;
        }

        queue<TreeNode *> q ;
        TreeNode * tn = NULL;

        q.push(root);
        q.push(NULL);

        while(!(q.front() == NULL && q.size() == 1)){

            tn = q.front() ;
            q.pop() ;

            if(tn->left != NULL){
                q.push(tn->left) ;
            }
            if(tn->right != NULL){
                q.push(tn->right) ;
            }

            if(q.front() == NULL){
                //right most
                ans.push_back(tn->val) ;

                q.pop();
                q.push(NULL) ;

            }
            
        }

        return ans ;



    }
};