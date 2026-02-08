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

//
class Solution {
private: 
int recc(TreeNode* curr, bool& isHB){
    if(curr == NULL) return 0;
    
    int l = recc(curr->left, isHB);
    int r = recc(curr->right, isHB);
    
    if(abs(l - r) > 1){
        isHB = false;
    }

    return max(l, r) + 1;
}

public:
    bool isBalanced(TreeNode* root) {
        bool isHB = true;
        recc(root, isHB);
        return isHB;
    }
};