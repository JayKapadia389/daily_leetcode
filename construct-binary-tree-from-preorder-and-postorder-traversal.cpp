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

    vector<int> preorder_;
    vector<int> postorder_;

    TreeNode* recc(int preL, int preR, int postL, int postR) {

        TreeNode* curr = new TreeNode(preorder_[preL]);

        if (preL == preR) {
            return curr;
        }

        int midPre = preL + 1;
        int midPost;

        for (int i = postL; i < postR; ++i) {
            if (postorder_[i] == preorder_[midPre]) {
                midPost = i;
                break;
            }
        }

        int leftBoundinPre = midPre;

        for (int j = midPre + 1; j <= preR; ++j) {
            for (int k = postL; k <= midPost - 1; ++k) {
                if (preorder_[j] == postorder_[k]) {
                    leftBoundinPre = j;
                    break;
                }
            }
        }

        cout << midPre << " " << leftBoundinPre << " " << postL << " " << midPost;

        curr->left = recc(midPre, leftBoundinPre, postL, midPost);

        if (leftBoundinPre != preR) {
            curr->right = recc(leftBoundinPre + 1, preR, midPost + 1, postR - 1);
        }

        return curr;

    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        preorder_ = preorder;
        postorder_ = postorder;
        int n = preorder.size();
        return recc(0, n - 1, 0, n - 1);
    }
};