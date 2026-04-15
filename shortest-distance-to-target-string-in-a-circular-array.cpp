class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int mn_dis = INT_MAX, n = words.size();

        for(int i = 0; i < n; ++i){
            int l = startIndex, r = i;
            if(l > r){
                swap(l, r);
            }

            if(words[i] == target){
                dis = min({dis, r - l, l + (n - r)});
            }
        }

        return (dis == INT_MAX)? -1 : dis;
    }
};