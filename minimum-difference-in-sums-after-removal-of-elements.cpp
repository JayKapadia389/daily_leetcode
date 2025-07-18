class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n = nums.size() , n_by_3 = n/3; 
        vector<long long> left_add(n , 0) ; 
        vector<long long> right_add(n , 0) ; 

        //max-heap
        priority_queue<int> pq(nums.begin() , nums.begin() + n_by_3) ; 
        left_add[0] = nums[0] ;  
        for(int i = 1 ; i < n_by_3 ; ++i){
            left_add[i] = left_add[i-1] + nums[i] ; 
        }

        for(int i = n_by_3 ; i < (n - n_by_3); ++i){
            if(nums[i] < pq.top()){
                int top = pq.top() ; 
                pq.pop();
                pq.push(nums[i]) ; 

                left_add[i] = left_add[i-1] - top + nums[i] ; 
            }
            else{
                left_add[i] = left_add[i-1] ; 
            }
        }

        //min-heap 
        priority_queue<int, vector<int> , greater<int>> pq2(nums.end()-n_by_3 , nums.end()) ; 
        right_add[n-1] = nums[n-1] ;
        for(int i = n-2 ; i >= (n - n_by_3) ; --i){
            right_add[i] = right_add[i+1] + nums[i] ; 
        }

        for(int i = (n - (n_by_3 + 1)) ; i >= n_by_3 ; --i){
            if(nums[i] > pq2.top()){
                int top = pq2.top() ; 
                pq2.pop();
                pq2.push(nums[i]) ; 

                right_add[i] = right_add[i+1] - top + nums[i] ; 
            }
            else{
                right_add[i] = right_add[i+1] ; 
            }
        }

        long long ans = LONG_LONG_MAX ; 

        for(int i = n_by_3 -1 ; i <= (n - (n_by_3 + 1)); ++i){
            ans = min(ans , left_add[i] - right_add[i+1]); 
        }

        return ans ; 
    }
};