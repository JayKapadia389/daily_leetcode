class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<vector<int>> validTriplets;

        for (auto triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                validTriplets.push_back(triplet);
            }
        }

        vector<int> maximizedTriplet(3, 0);

        for (auto triplet : validTriplets) {
            maximizedTriplet[0] = max(maximizedTriplet[0], triplet[0]);
            maximizedTriplet[1] = max(maximizedTriplet[1], triplet[1]);
            maximizedTriplet[2] = max(maximizedTriplet[2], triplet[2]);
        }

        if (maximizedTriplet == target) {
            return true;
        }

        return false;

    }
};