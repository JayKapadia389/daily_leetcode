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
    int maxLevelSum(TreeNode* root) {
        long long mx_sum = LLONG_MIN;
        int mx_level, level = 1;
        queue<TreeNode *> q;

        q.push(root);

        while(!q.empty()){
            int len = q.size();
            int sum = 0;

            // iterate on level
            for(int i = 0; i < len; ++i){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }

            if(sum > mx_sum){
                mx_sum = sum;
                mx_level = level; 
            }

            ++level;
        }
        return mx_level;
    }
};