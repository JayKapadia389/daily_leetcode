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
    void recc(TreeNode* curr, int& ans, int sum){
        if(curr == NULL) return;

        sum <<= 1;
        sum += (curr->val);

        if(curr->left == NULL && curr->right == NULL){
            ans += sum;
            return;
        }

        recc(curr->left, ans, sum);
        recc(curr->right, ans, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        recc(root, ans, 0);
        return ans;
    }
};