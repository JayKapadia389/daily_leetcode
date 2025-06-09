class Solution {
public:

    long long ans_ ; 
    long long count_ ; 
    int k_ ,n_;

    bool recc(string curr){

        if(++count_ == k_){
            ans_ = stoi(curr) ; 
            return true ; 
        } 

        for(int i = 0 ; i < 10 ; ++i){

            string next_str = curr + to_string(i) ; 
            int next_num = stoi(next_str) ;

            if(next_num > n_){
                return false ; 
            }

            if(recc(next_str)){
                return true ; 
            }

        }

        return false ; 

    }

    int findKthNumber(int n, int k) {

        count_ = 0 ;
        k_ = k ;
        n_ = n ;  

        for(int i = 1 ; i < 10 ; ++i){
            if(recc(to_string(i))){ 
                return ans_ ; 
            }
        }
        return 0 ; 
    }
};