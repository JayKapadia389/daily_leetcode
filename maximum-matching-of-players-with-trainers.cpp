class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin() , players.end()) ; 
        sort(trainers.begin() , trainers.end()) ; 

        int c = 0 ; 
        int i = 0 , j = 0 ; 
        int n = players.size() , m = trainers.size() ; 

        while(i < n && j < m){
            if(players[i] <= trainers[j]){
                ++c ; 
                ++i; 
            }
            ++j ; 
        }

        return c; 
        
    }
};