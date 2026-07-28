// Solution 1: O(nlogn)
// sort
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        sort(s.begin(), s.begin() + n/2);
        sort(s.begin() + n/2 + ((n % 2 == 0) ? 0 : 1), s.end(), greater<>());
        return s;
    }
};


// Solution 2: O(n)
// counting sort
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        ans.reserve(n);
        string left = "";
        left.reserve(n/2);
        string right = "";
        right.reserve(n/2);
        vector<int> freq(26, 0);

        for(int i = 0; i < n/2; ++i){
            ++freq[s[i] - 'a'];
        }

        int sum = 0;
        for(int i = 0; i < 26; ++i){
            sum += freq[i];
            while(freq[i]--){
                left.push_back('a' + i);
            }
        }

        right = left;
        reverse(right.begin(), right.end());

        ans += left;
        if(n % 2 != 0){
            ans += s[n/2];
        }
        ans += right;
        return ans;
    }
};