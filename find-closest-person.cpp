class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(x - z);
        int b = abs(y - z); 
        
        return (a >= b) ? ((a > b) ? 2 : 0) : 1; 
    }
};