class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b){
        if(a.second != b.second){
            return a.second < b.second;
        }
        else{
            return a.first > b.first;
        }
    }

    vector<int> frequencySort(vector<int>& nums) {

        map<int,int> freq_m;

        for(auto num : nums){
            ++freq_m[num];
        }

        vector<pair<int,int>> v;

        for(auto [value, freq] : freq_m){
            v.push_back({value,freq});
        }

        sort(v.begin() , v.end() , comp);
        vector<int> ans;

        for(auto p : v){
            for(int i = 0; i < p.second; ++i){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};