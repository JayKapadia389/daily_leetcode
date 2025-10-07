class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        set<int> idcs;
        vector<int> ans(n, 1);
        unordered_map<int,int> filled;

        for(int i = 0; i < n; ++i){
            if(rains[i] == 0){
                idcs.insert(i);
            }
            else{
                ans[i] = -1;
                if(filled.find(rains[i]) != filled.end()){
                    auto it = idcs.lower_bound(filled[rains[i]]);
                    if(it == idcs.end()){
                        return {};
                    }
                    
                    ans[*it] = rains[i];
                    idcs.erase(it);
                }
                filled[rains[i]] = i;
            }
        }

        return ans;
    }
};