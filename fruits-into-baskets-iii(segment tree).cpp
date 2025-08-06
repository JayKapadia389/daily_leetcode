class SegmentTree{
    public:
    vector<int> seg;

    SegmentTree(vector<int> arr){
        int n = arr.size();
        seg.assign(4*n + 1,0);

        build(0,0,n-1,arr);
    }

    void build(int idx, int l, int r, vector<int>& arr){
        if(l == r){
            seg[idx] = arr[l];
            return;
        }

        int mid = (l+r)/2;
        build((idx << 1) + 1, l, mid, arr);
        build((idx << 1) + 2, mid+1, r, arr);

        seg[idx] = max(seg[(idx << 1) + 1] , seg[(idx << 1) + 2]);
    }

    bool search(int amt, int curr, int l,int r){
        // base case
        if(l == r){
            if(seg[curr] >= amt){
                seg[curr] = -1;
                return true;
            }
            return false;
        }

        if(seg[curr] < amt){
            return false;
        }

        int mid = (l+r)/2;
        search(amt, (curr << 1) + 1, l , mid) || search(amt, (curr << 1) + 2, mid + 1 , r);

        seg[curr] = max(seg[(curr << 1) + 1] , seg[(curr << 1) + 2]);
        return true;
    }
};

class Solution {

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree st(baskets);
        int ans = 0;

        for(auto amt : fruits){
            if(!st.search(amt, 0, 0, n-1)){ 
                ++ans;
            }
        }

        return ans;
    }
};