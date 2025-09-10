class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_map<int , unordered_set<int>> lang;
        int m = languages.size();

        for(int i = 0; i < m; ++i){
            for(auto l : languages[i]){
                lang[i+1].insert(l);
            }
        }

        vector<vector<int>> loose_fss;

        for(auto fs : friendships){
            bool found = 0;
            int u = fs[0], v = fs[1];

            for(int i = 1; i <= n; ++i){
                if(lang[u].contains(i) && lang[v].contains(i)){
                    found = 1;
                    break;
                }
            }

            if(!found){
                loose_fss.push_back(fs);
            }
        }

        int mn = INT_MAX;

        for(int i = 1; i <= n; ++i){
            int temp = 0;
            vector<bool> taught(m+1,0);

            for(auto fs : loose_fss){
                int u = fs[0] , v = fs[1];

                if(!(lang[u].contains(i) || taught[u])){
                    ++temp;
                }

                if(!(lang[v].contains(i) || taught[v])){
                    ++temp;
                }
                taught[u] = 1;
                taught[v] = 1;
            }

            mn = min(mn, temp);
        }

        return mn;
    }
};