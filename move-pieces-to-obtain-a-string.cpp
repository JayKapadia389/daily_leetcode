class Solution {
public:
    bool canChange(string start, string target) {

        string startReduced = "";
        vector<int> startReducedIdx;

        string targetReduced = "";
        vector<int> targetReducedIdx;

        for (int i = 0; i < start.length(); i++) {
            if (start[i] != '_') {
                startReduced += start[i];
                startReducedIdx.push_back(i);
            }
        }

        for (int i = 0; i < target.length(); i++) {
            if (target[i] != '_') {
                targetReduced += target[i];
                targetReducedIdx.push_back(i);
            }
        }

        if (startReduced != targetReduced)
            return false;

        for (int i = 0; i < targetReduced.length(); i++) {

            if (targetReduced[i] == 'L' && (startReducedIdx[i] - targetReducedIdx[i]) < 0) {
                return false;
            }

            if (targetReduced[i] == 'R' && (startReducedIdx[i] - targetReducedIdx[i]) > 0) {
                return false;
            }

        }

        return true;

    }
};