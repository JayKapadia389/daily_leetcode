// solution 1
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> base = {
            12, 23, 34, 45, 56, 67, 78, 89,
            123, 234, 345, 456, 567, 678, 789,
            1234, 2345, 3456, 4567, 5678, 6789,
            12345, 23456, 34567, 45678, 56789,
            123456, 234567, 345678, 456789,
            1234567, 2345678, 3456789,
            12345678, 23456789,
            123456789
        };

        int n = base.size();
        int i = 0, j = n - 1;

        while(i < n && base[i] < low) {
            ++i;
        }
        while(j >= 0 && base[j] > high) {
            --j;
        }

        if(i > j) return vector<int>();

        return vector<int>(base.begin() + i, base.begin() + j + 1);
    }
};

// solution 2
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q({12, 23, 34, 45, 56, 67, 78, 89});
        vector<int> ans;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr > high) break;

            if(curr >= low) ans.push_back(curr);

            int last_digit = curr % 10;
            if(last_digit != 9) {
                curr *= 10;
                curr += (last_digit + 1);
                q.push(curr);
            }
        }

        return ans;
    }
};