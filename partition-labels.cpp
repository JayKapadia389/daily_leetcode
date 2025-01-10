class Solution {
public:
    vector<int> partitionLabels(string s) {

        map<char, vector<int>> m;

        for (int i = 0; i < s.length(); ++i) {
            m[s[i]].push_back(i);
        }

        vector<pair<int, int>> events;

        for (auto i : m) {
            events.push_back({ (i.second)[0] , -1 });
            events.push_back({ (i.second)[(i.second).size() - 1] , 1 });
        }

        sort(events.begin(), events.end());

        int last = -1, presum = 0;
        vector<int> ansVec;

        for (auto event : events) {
            presum += event.second;
            if (presum == 0) {
                ansVec.push_back(event.first - last);
                last = event.first;
            }
        }

        return ansVec;
    }
};