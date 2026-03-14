// greedy + minheap
#define ll long long
#define pii pair<int, int>

class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& t) {
        priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<>> pq;

        for(int i = 0; i < t.size(); i++){
            ll tm = t[i];
            pq.push({tm, {tm, 1}});
        }

        ll res = 0;

        while(h > 0){
            auto cur = pq.top();
            pq.pop();

            ll next_total_time = cur.first;
            int wt = cur.second.first;
            int next_freq = cur.second.second;

            res = next_total_time;
            h--;

            ll new_next_freq = next_freq + 1;
            ll new_next_total_time = new_next_freq * wt + next_total_time;
            pq.push({new_next_total_time, {wt, (int)new_next_freq}});
        }

        return res;
    }
};

// binary search + math(quadratic formula) 
// best
#define ll long long

class Solution {
public:
    bool isEnough(const int& mountainHeight, const vector<int>& workerTimes, const ll& t){
        long long sum = 0;

        for(ll x : workerTimes){
            ll work = t / x, k;
            k = (-1 + sqrt(1 + 8*work)) / 2;
            sum += k;
        }

        return (sum >= mountainHeight);
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll t, mid;

        int maxWorkerTimes = *max_element(workerTimes.begin(), workerTimes.end());
        ll l = 1, r = static_cast<long long>(maxWorkerTimes) *
                             mountainHeight * (mountainHeight + 1) / 2;
        
        while(l <= r){
            mid = (l+r)/2;

            bool indicator = isEnough(mountainHeight, workerTimes, mid);
            if(indicator){
                t = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return t;
    }
};

// nested binary search 
#define ll long long

class Solution {
public:
    bool isEnough(const int& mountainHeight, const vector<int>& workerTimes, const ll& t){
        long long sum = 0;

        for(ll x : workerTimes){
            ll y = (t * 2) / x;
            ll l = 0, r = 1e5, mid, m = 0;

            while(l <= r){
                mid = (l + r)/2;

                if(mid*(mid+1) <= y){
                    m = mid;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }

            sum += m;
        }

        return (sum >= mountainHeight);
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll l = 0, r = LLONG_MAX, t, mid;
        
        while(l <= r){
            mid = (l+r)/2;

            bool indicator = isEnough(mountainHeight, workerTimes, mid);
            if(indicator){
                t = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return t;
    }
};