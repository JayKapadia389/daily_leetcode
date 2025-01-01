//O(n^2)

// class Solution {
// public:

//     int n_ , ans_; 
//     string s_ ;

//     void fun(int mid){

//         int z = 0 , o = 0  ;

//         for(int i = 0 ; i< n_ ; i++){

//             if(i <= mid && s_[i] == '0'){
//                 ++z ; 
//             }
//             if(i>mid && s_[i] == '1'){
//                 ++o ; 
//             }

//             ans_ = max(ans_ , z+o) ; 
//         }


//     }

//     int maxScore(string s) {

//         s_ = s ; 
//         n_ = s.length() ; 
//         ans_ = 0 ; 

//         for(int i = 0 ; i < n_-1 ; i++ ){

//             fun(i) ; 

//         }

//         return ans_ ; 

//     }
// };


//O(n)
class Solution {
public:
    int maxScore(string s) {

        int n = s.length();

        vector<int> presum(n, 0);

        int o = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '1') {
                ++o;
            }
            presum[i] = o;
        }

        int ans = 0;
        int z = 0, lastPresum = presum[n - 1];

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                ++z;
            }

            ans = max(ans, z + (lastPresum - presum[i]));
        }
        return ans;

    }
};