class Solution {
public:
    int reverse(int num){
        int reverse_num = 0;

        while(num != 0){
            reverse_num *= 10;
            reverse_num += (num%10);
            num /= 10;
        }

        return reverse_num;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> m;
        int mn_dis = INT_MAX, n = nums.size();
        for(int i = n-1; i >= 0; --i){
            int reverse_num = reverse(nums[i]);
            if(m.find(reverse_num) != m.end()){
                mn_dis = min(mn_dis, m[reverse_num] - i);
            }
            m[nums[i]] = i;
        }

        return (mn_dis == INT_MAX)? -1 : mn_dis;
    }
};