class Solution {
public:
    int maximumGain(string s, int x, int y) {

        if(s.length() == 1){
            return 0;
        }

        string check = (x >= y)? "ab":"ba";
        char ch1 = check[0], ch2 = check[1];
        int high = max(x,y);
        int low = min(x,y);

        stack<char> st1;
        int ans = 0;
        st1.push(s[0]);

        for(int i = 1; i < s.length(); ++i){
            if(!st1.empty() && s[i] == ch2 && st1.top() == ch1){
                st1.pop();
                ans+=high;
            }
            else{
                st1.push(s[i]);
            }
        }

        stack<char> st2;

        while(!st1.empty()){
            char curr = st1.top();
            st1.pop();

            if(!st2.empty() && curr == ch2 && st2.top() == ch1){
                st2.pop();
                ans+=low;
            }
            else{
                st2.push(curr);
            }
        }

        return ans;
    }
};