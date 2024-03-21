class TimeMap {
public:

    map<string ,  vector<pair<int , string>> > m ; 

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        m[key].push_back({timestamp ,  value}) ; 

        return ;
        
    }
    
    string get(string key, int timestamp) {

        if(m[key].size() == 0){
            return "" ;
        }

        vector<pair<int , string>> v = m[key] ;

        string ans = "" ;

        int  l = 0  , r = v.size() -1  , mid ;

        while(l <= r){

            mid = l + (r - l) / 2;

            if(timestamp == v[mid].first){
                return v[mid].second ;
            }
            else if(timestamp > v[mid].first){
                ans = v[mid].second ;
                l = mid +1  ;
            }
            else{
                r=mid -1  ;
            }
        }

        return ans ;
       
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */