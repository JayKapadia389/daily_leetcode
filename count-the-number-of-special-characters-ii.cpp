// FSM
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> states(26, 0);
        int cnt = 0;

        for(auto ch : word){
            int state, new_state, letter_case, idx;
            if(ch >= 'a' && ch <= 'z'){
                letter_case = 0;
                idx = ch - 'a';
            }
            else{
                letter_case = 1;
                idx = ch - 'A';
            }

            state = states[idx];
            new_state = state;

            switch(state){
                case 0:
                    if(letter_case){
                        new_state = 3;
                    }
                    else{
                        new_state = 1;
                    }
                break;
                case 1:
                    if(letter_case){
                        new_state = 2;
                        ++cnt;
                    }
                break;
                case 2:
                    if(!letter_case){
                        new_state = 3;
                        --cnt;
                    }
            }

            states[idx] = new_state;
        }

        return cnt;
    }
};

// cleaner editorial solution
//
// class Solution {
// public:
//     int numberOfSpecialChars(string word) {
//         vector<int> lastLow(26, -1), firstUp(26, -1);
//         for (int i = 0; i < word.size(); i++) {
//             char c = word[i];
//             if (islower(c)) {
//                 lastLow[c - 'a'] = i;
//             } else {
//                 if (firstUp[c - 'A'] == -1) {
//                     firstUp[c - 'A'] = i;
//                 }
//             }
//         }
//         int ans = 0;
//         for (int i = 0; i < 26; i++) {
//             if (lastLow[i] != -1 && firstUp[i] != -1 &&
//                 lastLow[i] < firstUp[i]) {
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };