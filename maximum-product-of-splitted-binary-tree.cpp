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

int mod = 1e9 + 7;
class Solution {
private:
long long findSum(TreeNode* curr){
    if(curr == NULL) return 0;
    return findSum(curr->left) + findSum(curr->right) + curr->val;
}

long long findMaxProduct(const TreeNode* curr, const long long& sum, long long& maxProduct){
    if(curr == NULL) return 0;

    long long leftSum = findMaxProduct(curr->left, sum, maxProduct);
    long long rightSum = findMaxProduct(curr->right, sum, maxProduct);

    maxProduct = max(maxProduct, (sum - leftSum)*leftSum);
    maxProduct = max(maxProduct, (sum - rightSum)*rightSum);

    return leftSum + rightSum + curr->val;
}

public:
    int maxProduct(TreeNode* root) {
        long long sum = 0, maxProduct = LLONG_MIN;
        sum = findSum(root);
        findMaxProduct(root, sum, maxProduct);

        return (maxProduct % mod);
    }
};