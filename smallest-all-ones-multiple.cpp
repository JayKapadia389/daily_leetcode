class Solution {
public:
    int minAllOneMultiple(int k) {

        if(k%2==0 || k%5==0) return -1;

        int remain = 0;

        for(int i=1;i<=k;i++)
            {
                remain = (remain*10+1)%k;
                if(remain ==0) return i;
            }

        return -1;
    }
};