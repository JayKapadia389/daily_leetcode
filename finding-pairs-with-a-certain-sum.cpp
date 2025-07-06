class FindSumPairs {
public:

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto num : nums2){
            ++m[num] ;
        }
        this->nums1 = nums1 ; 
        this->nums2 = nums2 ; 
    }
    
    void add(int index, int val) {
        --m[nums2[index]] ;  
        nums2[index] += val ; 
        ++m[nums2[index]] ;  
    }
    
    int count(int tot) {
        int diff;
        int c = 0 ; 

        for(auto num : nums1){
            diff = tot-num ; 
            if(diff > 0){
                if(m.find(diff) != m.end()){
                    c += m[diff] ; 
                } 
            }
        }

        return c ; 
    }

private:
    unordered_map<int, int> m ; 
    vector<int> nums1 ; 
    vector<int> nums2 ;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */