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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> nodes;
        unordered_set<int> has_parent;
        unordered_map<int, TreeNode*> value_to_node;
        TreeNode* root;

        for(auto desc : descriptions){
            int parent_val = desc[0];
            int child_val = desc[1];
            bool is_left = desc[2];

            nodes.insert(parent_val);
            nodes.insert(child_val);
            has_parent.insert(child_val);

            TreeNode* child;
            if(value_to_node.find(child_val) == value_to_node.end()){
                value_to_node[child_val] = new TreeNode(child_val);
            }
            child = value_to_node[child_val];

            TreeNode* parent;
            if(value_to_node.find(parent_val) == value_to_node.end()){
                value_to_node[parent_val] = new TreeNode(parent_val);
            }
            parent = value_to_node[parent_val];

            if(is_left){
                parent -> left = child;
            }
            else{
                parent -> right = child;
            }
        }

        for(auto node : nodes){
            if(!has_parent.contains(node)){
                root = value_to_node[node];
                break;
            }
        }

        return root;
    }
};