// brute force

// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {

//         int n = prices.size() , curr; 

//         for(int i = 0 ; i < n - 1; i++){
//             curr = prices[i] ; 

//             for(int j = i+1 ; j < n ; j++ ){
//                 if(prices[j] <= curr){
//                     prices[i] -= prices[j] ; 
//                     break ; 
//                 }
//             }
//         }

//         return prices ; 

//     }
// };

//moonotonic stack solution

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<int> st;
        int n = prices.size(), curr;

        for (int i = n - 1; i >= 0; --i) {

            curr = prices[i];

            while (!st.empty() && curr < st.top()) {
                st.pop();
            }

            if (st.empty()) {
                st.push(curr);
            }
            else {
                prices[i] -= st.top();

                if (curr != st.top()) {
                    st.push(curr);
                }
            }

        }

        return prices;

    }
};