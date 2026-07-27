class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        int n = num.size();
        st.reserve(n - k + 1);

        for(auto ch : num){
            while(k != 0 && !st.empty() && st.back() > ch){
                st.pop_back();
                --k;
            }

            if(ch != '0' || !st.empty()){
                st.push_back(ch);
            }
        }

        while(!st.empty() && k != 0){
            st.pop_back();
            --k;
        }

        string ans = "";
        ans.reserve(n - k + 1);

        if(st.empty()){
            return "0";
        }
        else {
            while(!st.empty()){
                ans.push_back(st.back());
                st.pop_back();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};