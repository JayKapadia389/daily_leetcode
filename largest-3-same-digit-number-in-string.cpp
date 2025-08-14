class Solution {
public:
    string largestGoodInteger(string num) {
        int mx = INT_MIN;
        string ans = "";

        for(int i = 2; i < num.size(); ++i){
            if((num[i] == num[i-1]) && (num[i] == num[i-2])){
                int n = stoi(num.substr(i-2, 3));
                if(n > mx){
                    ans = num.substr(i-2, 3);
                    mx = n;
                }
            }
        }
        return ans;
    }
};