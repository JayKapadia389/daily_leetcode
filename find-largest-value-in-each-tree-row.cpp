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
    vector<int> largestValues(TreeNode* root) {

        vector<int> ansVec;

        if (root == NULL)
            return ansVec;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int mx;
        TreeNode* curr;

        while (!q.empty()) {

            mx = INT_MIN;

            while (q.front() != NULL) {

                curr = q.front();
                q.pop();

                mx = max(mx, curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            q.pop();

            ansVec.push_back(mx);
            if (!q.empty())
                q.push(NULL);

        }

        return ansVec;
    }
};