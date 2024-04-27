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

    TreeNode * core(vector<int> preorder , vector<int> inorder , int l , int r , int l2 ){

        if(r < l ){
            return NULL ;
        }

        int inorderIdx = -1;
        int preorderIdx = -1;

        for(int j = l2 ; (j < preorder.size()) && (inorderIdx == -1) ; j++){

            for(int i = l ; (i <= r) && (inorderIdx == -1); i++){

                if(preorder[j] == inorder[i]){
                    inorderIdx = i ;
                    preorderIdx = j ;

                }

            }
                
        }

        TreeNode * root = new TreeNode(inorder[inorderIdx]) ;

        //left ;
        root->left = core(preorder , inorder , l , inorderIdx - 1 , preorderIdx +1  ) ;
        //righgt;
        root->right = core(preorder , inorder , inorderIdx + 1 ,  r , preorderIdx +1) ;

        return root ;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int l = 0 ;
        int r = preorder.size() - 1; 

        return core( preorder , inorder ,  l ,  r ,0) ;
        
    }
};