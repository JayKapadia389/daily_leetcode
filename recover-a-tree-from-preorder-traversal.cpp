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

    vector<pair<int, int>> v; // <value , depth>
    int iter;
    int size;

    void recc(int curr_depth, TreeNode* curr_node) {

        if (iter != size && v[iter].second == curr_depth + 1) {
            curr_node->left = new TreeNode(v[iter].first);
            ++iter;

            recc(curr_depth + 1, curr_node->left);

            if (iter != size && v[iter].second == curr_depth + 1) {

                curr_node->right = new TreeNode(v[iter].first);
                ++iter;

                recc(curr_depth + 1, curr_node->right);
            }
        }

        return;
    }

    TreeNode* recoverFromPreorder(string traversal) {

        int c = 0, len = traversal.length();

        for (int i = 0; i < len; ++i) {
            if (traversal[i] == '-') {
                ++c;
            }
            else {

                int st = i;

                while (i != (len - 1) && traversal[i + 1] != '-') {
                    ++i;
                }

                int val = stoi(traversal.substr(st, i - st + 1));
                v.push_back({ val , c });

                c = 0;
            }
        }

        iter = 0;
        size = v.size();

        TreeNode* root = new TreeNode(v[iter].first);
        ++iter;

        recc(0, root);
        v.clear();

        return root;

    }
};