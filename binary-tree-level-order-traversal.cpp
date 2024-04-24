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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans ; 
        vector<int> temp ; 

        if(root == NULL){
            return ans ;
        }

        TreeNode * t = NULL ;

        queue<TreeNode *> q;

        q.push(root);
        q.push(NULL) ;

        while(!(q.front() == NULL && q.size() == 1)){

            if(q.front() != NULL){

                t = q.front() ;
                q.pop() ;

                temp.push_back(t->val) ;

                if(t->left != NULL){
                    q.push(t->left) ;
                }
                if(t->right != NULL){
                    q.push(t->right) ;
                }

            }
            else{

                ans.push_back(temp) ;
                temp.clear() ;
                q.pop() ;
                q.push(NULL) ;

            }

        }

        ans.push_back(temp) ;

        return ans ;
        
    }
};