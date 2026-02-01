// contest 
// not upsolved
class RideSharingSystem {
private:
queue<int> drivers;
int rider_seq;
map<int, int> m;
set<pair<int, int>> s;

public:
    RideSharingSystem() {
        rider_seq = 0;
        m.clear();
        s.clear();
        drivers = queue<int>();
    }
    
    void addRider(int riderId) {
        ++rider_seq;
        m[riderId] = rider_seq;
        s.insert({rider_seq, riderId});
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ans(2, -1);
        
        if(!s.empty() && !drivers.empty()){
            ans[0] = drivers.front();
            drivers.pop();

            auto it = s.begin();
            ans[1] = it->second;
            s.erase(it);
        }
        
        return ans;
    }
    
    void cancelRider(int riderId) {
        if(m.find(riderId) != m.end()){
            s.erase({m[riderId], riderId});
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */