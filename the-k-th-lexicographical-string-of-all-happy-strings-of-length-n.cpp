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
