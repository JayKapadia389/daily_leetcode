class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        map<int, bool> m;
        int curr;

        for (int i = 0; i < arr.size(); i++) {
            curr = arr[i];

            //check if it is double of something
            if (curr % 2 == 0 && m[curr / 2]) {
                return true;
            }
            else if (m[curr * 2]) { //check if half of something
                return true;
            }

            //update
            m[curr] = 1;

        }
        return false;

    }
};