class Solution {
private:
    bool is_prime(int num){
        if(num == 2){
            return true;
        }
        if(num == 1){
            return false;
        }

        for(int i = 2; i <= sqrt(num); ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2){
            return (n-1);
        }

        // Fix: map values to their indices
        unordered_map<int, vector<int>> val_to_indices;
        for(int i = 0; i < n; ++i){
            val_to_indices[nums[i]].push_back(i);
        }

        vector<bool> visited(n, 0);
        vector<bool> is_processed(1000001, 0);
        queue<int> q;

        int jump = 1;
        q.push(0);
        visited[0] = 1;
        int len = 1;

        while(!q.empty()){
            for(int c = 0; c < len; ++c){
                int i = q.front();
                q.pop();

                if(i-1 >= 0 && !visited[i-1]){
                    if(i-1 == n-1) return jump;
                    visited[i-1] = 1;
                    q.push(i-1);
                }

                if(i+1 < n && !visited[i+1]){
                    if(i+1 == n-1) return jump;
                    visited[i+1] = 1;
                    q.push(i+1);
                }

                if(!is_processed[nums[i]] && is_prime(nums[i])){
                    is_processed[nums[i]] = 1;
                    for(int j : val_to_indices[nums[i]]){
                        if(!visited[j]){
                            if(j == n-1) return jump;
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                    // Optional: free memory
                    val_to_indices.erase(nums[i]);
                }
            }
            ++jump;
            len = q.size();
        }

        return -1;
    }
};
