class Solution {
private:
int f(int h) {
    if(h == 12) return 0;
    return h * 30;
}

double g(int m){
    return 0.5 * m;
}

int k(int m){
    return 6 * m;
}

public:
    double angleClock(int h, int m) {
        double hour = f(h) + g(m);
        int minutes = k(m);
        double angle = abs(hour - minutes);
        if(angle > 180){
            return 360 - angle;
        }
        return angle;
    }
};