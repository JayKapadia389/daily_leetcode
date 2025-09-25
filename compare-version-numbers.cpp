class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = version1.size(), s2 = version2.size();
        int i = 0, j = 0;
        vector<int> version1_num;
        vector<int> version2_num;

        while(j <= s1){
            if(version1[j] == '.' || j == s1){
                version1_num.push_back(stoi(version1.substr(i,j)));
                i = j+1;
            }
            ++j;
        }

        i = 0, j = 0;
        while(j <= s2){
            if(version2[j] == '.' || j == s2){
                version2_num.push_back(stoi(version2.substr(i,j)));
                i = j+1;
            }
            ++j;
        }

        int m = version1_num.size(), n = version2_num.size();
        i = 0;
        for(; i < min(m,n); ++i){
            if(version1_num[i] < version2_num[i]){
                return -1;
            }
            else if(version1_num[i] > version2_num[i]){
                return 1;
            }
        }

        if(m == n){
            return 0;
        }

        if(m > n){
            for(int j = i; j < m; ++j){
                if(version1_num[j] != 0){
                    return 1;
                }
            }
        }
        else{
            for(int j = i; j < n; ++j){
                if(version2_num[j] != 0){
                    return -1;
                }
            }
        }
        return 0;
    }
};