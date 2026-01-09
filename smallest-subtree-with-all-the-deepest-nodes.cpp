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
pair<int, TreeNode*> recc(TreeNode* curr){
    if(curr == NULL) return {0, NULL};
    pair<int, TreeNode*> L = recc(curr->left);
    pair<int, TreeNode*> R = recc(curr->right);

    if(L.first == R.first){
        return {L.first + 1, curr};
    }
    else{
        pair<int, TreeNode*> T = (L.first > R.first) ? L : R;
        return {T.first + 1, T.second};
    }
}

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return recc(root).second;
    }
};