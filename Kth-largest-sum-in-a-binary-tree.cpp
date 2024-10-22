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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        long long levelSum = 0 ;
        vector<long long> v ;
        queue<TreeNode *> q ;
        q.push(root) ;
        q.push(NULL) ;

        while(true){

            TreeNode * curr = q.front() ;
            cout << curr << endl ;
            q.pop() ;

            if(curr){

                levelSum += (curr->val) ;
                if(curr->left){
                    q.push(curr->left) ;
                }
                if(curr->right){
                    q.push(curr->right) ;
                }

            }
            else{

                v.push_back(levelSum) ;
                levelSum = 0;

                if(q.empty()){
                    break ;
                }
                else{
                    q.push(NULL) ;
                }

            }

        }

        if(k > v.size()){
            return -1 ;
        }
        else{
            sort(v.begin() , v.end() , greater<>()) ;

            return v[k-1] ;

        }
        
    }
};