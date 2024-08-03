class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        map<char , int> freq ;

        for(int i = 0 ; i < tasks.size() ; i++){

            freq[tasks[i]]++ ;

        } 

        priority_queue<pair<int , char>> pq ;

        for(auto i : freq){

            pq.push({i.second , i.first}) ;

        }

        map<char , int> cooldown ;
        vector<pair<int , char>> temp_vec ;
        int clock = 0 ;

        while(!pq.empty()){

            while((cooldown[(pq.top()).second]) != 0 && (!pq.empty())){
                // push 
                temp_vec.push_back(pq.top()) ;

                pq.pop() ;
            }

            if(!pq.empty()){
                pair<int , char > p = pq.top() ;
                pq.pop() ;

                p.first = (p.first) -1 ;

                //sub ->if 0 dont push in pq
                if((p.first) != 0){
                    pq.push(p) ;
                } 

                cooldown[p.second] = n ;

                for(auto i : cooldown){

                    if(i.first != p.second){
                        (i.second)-- ;
                    }

                }




            }

            clock++ ;

            for(auto i : temp_vec){
                pq.push(i) ;
            }

        }


        return clock ;
        


        
    }
};