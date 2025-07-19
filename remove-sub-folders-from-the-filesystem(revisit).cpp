class Solution {
public:

    // returns whether `folder[i]` is the subfolder of `prev`.
    bool isSubFolder(string& prev, string& curr){
        int prev_len = prev.length();

        if(curr.length() <= prev_len){
            return false;
        }
        else if(curr.substr(0,prev_len) == prev && curr[l] == '/'){
            return true;
        }
        else{
        return false;
        }
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> answer;
        ans.reserve(folder.size());

        // most important
        sort(folder.begin(), folder.end());

        string prev = folder[0];
        answer.push_back(prev);

        for(int i = 1; i < folder.size(); ++i){
            if(!isSubFolder(prev, folder[i])){
                prev = folder[i]; 
                answer.push_back(prev);
            }
        }

        return ans;
    }
};