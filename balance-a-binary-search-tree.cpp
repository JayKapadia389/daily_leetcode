// O(n) time
// O(n) space

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
private:
void inOrderTraversal(TreeNode* curr, vector<int>& elements){
    if(curr == NULL) return;
    inOrderTraversal(curr->left, elements);
    elements.push_back(curr->val);
    inOrderTraversal(curr->right, elements);
}

TreeNode* constructBBST(int l, int r, const vector<int>& elements){
    if(r < l){
        return NULL;
    }

    int mid = (l+r)/2;
    TreeNode* curr = new TreeNode(elements[mid]);
    curr -> left = constructBBST(l, mid - 1, elements);
    curr -> right = constructBBST(mid + 1, r, elements);
    return curr;
}

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> elements;
        inOrderTraversal(root, elements);
        return constructBBST(0, elements.size()-1, elements);
    }
};