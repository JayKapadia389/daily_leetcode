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
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool odd = 0;

        queue<TreeNode*> qSec;
        stack<int> stSec;

        TreeNode* curr;

        while (!q.empty()) {

            curr = q.front();
            q.pop();

            if (curr) {

                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }

                if (odd) {
                    qSec.push(curr);
                    stSec.push(curr->val);
                }

            }
            else {

                if (odd) {
                    while (!qSec.empty()) {
                        qSec.front()->val = stSec.top();

                        qSec.pop();
                        stSec.pop();
                    }
                }

                odd = !odd;

                if (!q.empty()) {
                    q.push(NULL);
                }

            }

        } //while

        return root;

    } // function
};