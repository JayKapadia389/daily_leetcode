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

    int maxHeight;
    map<int , int> heights ;
    map<int , int> answers ;

    int getHeights(TreeNode * curr){

        int lh ,rh = 0 ;

        if(curr->left){
            lh = 1 + getHeights(curr->left);
        }
         if(curr->right){
            rh = 1 + getHeights(curr->right);
        }

        heights[curr->val] = max(lh , rh) ;
        return heights[curr->val] ;

    }

    void getAnswers(TreeNode * root){

        queue<TreeNode * > q ;

        if(root->left){
            q.push(root->left) ;
        }
        if(root->right){
            q.push(root->right) ;
        }

        q.push(NULL) ;

        while(!q.empty() && q.front()){

            TreeNode * first = q.front() ;
            q.pop() ;

            if(first->left){
                    q.push(first->left) ;
                }
                if(first->right){
                    q.push(first->right) ;
                }

            if(q.front() == NULL){
                answers[first->val] = maxHeight - heights[first->val] - 1 ;
                q.pop() ;
                
                q.push(NULL) ;
                continue ;
            }

            answers[first->val] = maxHeight ;

            TreeNode * second = q.front() ;
            q.pop() ;
            if(second->left){
                    q.push(second->left) ;
                }
                if(second->right){
                    q.push(second->right) ;
                }
            
            answers[second->val] = maxHeight ;

            int x , y , n , m ;

            if(heights[first->val] >= heights[second->val]){
                x = first->val ;
                m = heights[first->val] ;
                y = second->val ;
                n = heights[second->val] ;
            }
            else{
                x = second->val ;
                m = heights[second->val] ;
                y = first->val ;
                n = heights[first->val] ;
            }

            //loop
            if(!q.front()){
                q.pop();
                q.push(NULL) ;
            }
            else{

                while(true){

                    TreeNode * top = q.front() ;
                    q.pop() ;

                    if(top == NULL){
                        q.push(NULL) ;
                        break ;
                    }

                    answers[top->val] = maxHeight ;

                    if( heights[top->val] >= m){
                        y = x ;
                        n = m;
                        x = top->val ;
                        m = heights[x] ;
                    }

                    if(top->left){
                        q.push(top->left) ;
                    }

                    if(top->right){
                        q.push(top->right) ;
                    }
                    
                }

            }

            if(m!=n){
                answers[x] = maxHeight - (m - n) ;
            }

        }

        return ;

    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        maxHeight = 0 ;
        heights.clear() ;

        maxHeight = getHeights(root) ; //

        answers.clear() ;

        getAnswers(root) ; //

        vector<int> newHeights ;

        for(auto i : queries){
            newHeights.push_back(answers[i]) ;
        }

        return newHeights ;
        
    }
};