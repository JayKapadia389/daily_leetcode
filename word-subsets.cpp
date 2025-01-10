class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        map<char, int> finalm;
        map<char, int > tempm;

        for (auto w : words2) {
            tempm.clear();

            for (auto c : w) {
                ++tempm[c];
            }

            for (auto i : tempm) {
                finalm[i.first] = max(finalm[i.first], i.second);
            }
        }

        vector<string> universal;
        bool set;

        for (auto w : words1) {
            tempm.clear();

            for (auto c : w) {
                ++tempm[c];
            }

            set = 1;

            for (auto i : finalm) {
                if (tempm[i.first] < i.second) {
                    set = 0;
                    break;
                }
            }

            if (set) {
                universal.push_back(w);
            }
        }

        return universal;

    }
};