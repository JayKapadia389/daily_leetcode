// Binary search - O(nlogn) time 
// n = nums.size()

class Solution {
private:
int nonP(vector<int>& nums, int k){
    int op = 0;

    for(auto num : nums){
        op += (num/k);
        if(num%k != 0){
            op += 1;
        }
    }

    return op;
}
    
public:
    int minimumK(vector<int>& nums) {
        int l = 1, r = 1e5;
        int k;
        long long mid;

        while(l <= r){
            mid = (l + r)/2;

            if(nonP(nums, mid) <= mid*mid){
                k = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return k;
    }
};