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
class FindElements {
public:

    map<int, bool> m;

    void populate(int val, TreeNode* curr) {
        m[val] = 1;
        if (curr->left)
            populate(2 * val + 1, curr->left);
        if (curr->right)
            populate(2 * val + 2, curr->right);
        return;
    }

    FindElements(TreeNode* root) {
        populate(0, root);
    }

    bool find(int target) {
        return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */