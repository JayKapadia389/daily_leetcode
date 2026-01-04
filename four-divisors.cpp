class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(auto num : nums){
            float root = sqrt(num);
            int cnt = 0;
            int temp_sum = 0;
            bool more = 0;

            for(int divisor = 1; divisor <= root; ++divisor){
                if(num % divisor == 0){

                    if(cnt >= 4){
                        more = 1;
                        break;
                    }

                    temp_sum += divisor;
                    ++cnt;
                    
                    int quotient = num/divisor;
                    if(quotient != divisor){
                        temp_sum += quotient;
                        ++cnt;
                    }                   
                }
            }

            if(cnt == 4 && !more){
                ans += temp_sum;
            }
        }

        return ans;
    }
};

// Cleaner logic and code, same complexity
//
// int sumFourDivisors(vector<int>& nums) {
//     auto sum = 0;
//     for (auto n : nums) {
//         auto last_d = 0;
//         for (auto d = 2; d * d <= n; ++d) {
//             if (n % d == 0) {
//                 if (last_d == 0)
//                     last_d = d;
//                 else {
//                     last_d = 0;
//                     break;
//                 }
//             }
//         }
//         if (last_d > 0 && last_d != n / last_d) {
//             sum += 1 + n + last_d + n / last_d;
//         }            
//     }
//     return sum;
// }