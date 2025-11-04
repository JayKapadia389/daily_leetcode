class Solution {
private:
int xSum(vector<int>& nums, int i, int k, int x){
    vector<int> freq(51,0);

    for(int j = i; j < i+k; ++j){
        ++freq[nums[j]];
    }

    vector<pair<int,int>> v;

    for(int i = 0; i <= 50; ++i){
        if(freq[i] != 0){
            v.push_back({freq[i], i});
        }
    }

    sort(v.begin(), v.end(), greater<>());

    int ans = 0;

    for(int i = 0; i < x && i < v.size(); ++i){
        ans += (v[i].first * v[i].second) ; 
    }

    return ans;
}

public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);

        for(int i = 0; i < (n-k+1); ++i){
            ans[i] = xSum(nums, i, k, x);
        }

        return ans;
    }
};