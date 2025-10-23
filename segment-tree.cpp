#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MaxSegmentTree{
    private:
    vector<int> st;
    vector<int> arr;
    int n;

    void init(int idx, int l, int r){
        if(l == r){
            st[idx] = arr[l];
            return;
        }

        init(2*idx + 1, l , (l+r)/2);
        init(2*idx + 2, ((l+r)/2)+1 , r);

        st[idx] = max(st[2*idx + 1], st[2*idx + 2]);

        return;
    }

    int queryCore(int ql, int qr, int l, int r, int idx){
        // No overlap
        if(ql > r || qr < l){
            return INT_MIN;
        }
        // Complete overlap
        if(ql <= l && qr >= r){
            return st[idx];
        }
        // Partial overlap
        int mid = (l + r) / 2;
        return max(queryCore(ql, qr, l, mid, 2*idx+1), 
                   queryCore(ql, qr, mid+1, r, 2*idx+2));
    }

    public:
    MaxSegmentTree(vector<int>& arr){
        n = arr.size();
        this->arr = arr;
        st = vector<int>(4*n,0);
        init(0, 0, n-1);
    }

    int query(int ql, int qr){
        return queryCore(ql,  qr, 0, n-1, 0);
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout << "Array: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    MaxSegmentTree st(arr);
    cout << "Maximum in range [3,6]: " << st.query(3,6) << endl;
    
    return 0;
}