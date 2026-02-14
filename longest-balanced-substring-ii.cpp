class Solution {
private:
int mono(const string& s){
    int ans = 1, curr = 1;
    for(int i = 1; i < s.length(); ++i){
        if(s[i] == s[i-1]) ++curr;
        else curr = 1;
        ans = max(ans, curr);
    }
    return ans;
}

int duo(const string& s, char ch1, char ch2){
    int ans = 0, delta = 0;
    unordered_map<int, int> m;
    m[0] = -1;

    for(int i = 0; i < s.length(); ++i){
        char ch = s[i]; 

        if(ch != ch1 && ch != ch2){
            m = unordered_map<int, int>();
            m[0] = i;
            delta = 0;
            continue;
        }

        if(ch == ch1){
            ++delta;
        }
        else{
            --delta;
        }

        if(m.find(delta) != m.end()){
            ans = max(ans, i - m[delta]);
        }
        else{
            m[delta] = i;
        }
    }

    return ans;
}

int tri(const string& s){
    unordered_map<int, unordered_map<int, int>> m;
    m[0][0] = -1;
    vector<int> freq(3, 0);
    vector<int> delta;
    int ans = 0;

    for(int i = 0; i < s.length(); ++i){
        ++freq[s[i] - 'a'];

        delta = {freq[0] - freq[1], freq[0] - freq[2]};

        if(m.find(delta[0]) != m.end() && m[delta[0]].find(delta[1]) != m[delta[0]].end()){
            ans = max(ans, i - m[delta[0]][delta[1]]);
        }
        else{
            m[delta[0]][delta[1]] = i;
        }
    }

    return ans;
}

public:
    int longestBalanced(string s) {
        return max({
            mono(s),
            duo(s, 'a', 'b'),
            duo(s, 'b', 'c'),
            duo(s, 'a', 'c'),
            tri(s)
        });
    }
};