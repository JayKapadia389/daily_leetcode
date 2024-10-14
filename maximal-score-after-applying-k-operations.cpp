class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        long long score = 0 ;

        priority_queue<int> q ;

        for(auto i : nums){
            q.push(i) ;
        }

        for(int i =0  ; i < k ; i++){

            int top = q.top() ;
            q.pop() ;

            score += top ;

            q.push(ceil(top/3.00)) ;

        }

        return score ;
        
    }
};