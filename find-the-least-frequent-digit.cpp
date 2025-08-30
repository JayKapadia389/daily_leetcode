class Solution {
public:
    int getLeastFrequentDigit(int n) {
        map<int, int> m;
        int min_digit;
        int min_freq = INT_MAX;

        while(n != 0){
            int rem = n % 10;
            ++m[rem];
            n /= 10;
        }

        for(auto it : m){
            if(it.second < min_freq){
                min_digit = it.first;
                min_freq = it.second;
            }
        }

        return min_digit;
        
    }
};

// log base 10 (n) 

// int getLeastFrequentDigit(int n) {
//         vector<int> v(10, 0);
//         int min_freq = INT_MAX;

//         while(n != 0){
//             int rem = n % 10;
//             ++v[rem];
//             n /= 10;
//         }

//         for(int i = 0; i <= 9; ++i){
//             if(v[i] != 0 && v[i] < min_freq){
//                 min_digit = i;
//                 min_freq = v[i];
//             }
//         }
//         return min_digit;
//     }