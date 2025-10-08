class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<int,int>> spells_with_index;
        int n = spells.size();
        int m = potions.size();
        
        for(int i = 0; i < n; ++i){
            spells_with_index.push_back({spells[i], i});
        }

        sort(spells_with_index.begin(), spells_with_index.end());
        sort(potions.begin(), potions.end(), greater<int>());

        vector<int> pairs(n, m);

        int i = 0,j = 0;
        while(i < n && j < m){
            long long c = spells_with_index[i].first;
            c*=  potions[j];

            if (c >= success){
                ++j;
            }
            else{
                pairs[spells_with_index[i].second] = j;
                ++i;
            }
        }

        return pairs;
    }
};