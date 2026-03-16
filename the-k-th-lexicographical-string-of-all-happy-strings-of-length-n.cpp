// recursion + backtracking 
// O(2^n)
class Solution {
public:
    void generate(int n, string& curr, int& count, int k, string& result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;
            }
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                generate(n, curr, count, k, result);
                curr.pop_back();

                if (!result.empty()) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        int maxCount = 3 * pow(2, n - 1);
        if (k > maxCount) return "";

        int count = 0;
        string result;
        string curr;
        generate(n, curr, count, k, result);
        return result;
    }
};


// O(n) solution
class Solution {
public:
    void recc(string& ans, int n, int k){
        if(n == 0){
            return;
        }

        int q = k / pow(2, n - 1);
        int r = k % ((int) pow(2, n - 1));

        if(ans.back() == 'a'){
            ans += (q == 0)? 'b' : 'c';
        }
        else if(ans.back() == 'b'){
            ans += (q == 0)? 'a' : 'c';
        }
        else if(ans.back() == 'c'){
            ans += (q == 0)? 'a' : 'b';
        }

        recc(ans, n - 1, r);
    }

    string getHappyString(int n, int k) {
        int q = (k - 1) / pow(2, n - 1);
        int r = (k - 1) % ((int) pow(2, n - 1));

        string ans = "";
        ans.reserve(n);

        if(q == 0) ans += "a";
        else if(q == 1) ans += "b";
        else if(q == 2) ans += "c";
        else return ans;

        recc(ans, n - 1, r);
        return ans;
    }
};
