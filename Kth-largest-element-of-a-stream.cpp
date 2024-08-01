class KthLargest {
public:

    private : 
        int k ;
        int size ;
        priority_queue<int , vector<int> , greater<int>> pq ;

    public :
    KthLargest(int k, vector<int>& nums) {

        this->k = k ;

        size = nums.size() ;

        sort(nums.begin() , nums.end()) ;

        int n =( k < nums.size()) ? k : nums.size() ;

        int x = 1 ;

        for(int i = (nums.size() -1); x <= n ; i-- , x++){
            pq.push(nums[i]) ;
        }
        
    }
    
    int add(int val) {

        if(size < k){

         pq.push(val) ;
         size++;
         return pq.top() ;

        }

        int tp = pq.top() ;

        if(val > tp){
         pq.pop() ;
         pq.push(val) ;
        }
        
        tp = pq.top() ;
        return tp ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */