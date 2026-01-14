class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double L = 0, R = 1e9;
        double half_area = 0, 
        long long total_area = 0; 

        for(const auto& square : squares){
            total_area += (static_cast<long long>(square[2])*square[2]);
        }

        half_area = static_cast<double>(total_area)/2; // As the number is N/2^k form, we can guarantee that half_area is exact and not approximate.

        while((R - L) > 2*1e-5){
            double yc = (L + R) / 2;
            double area_y = 0;

            for(const auto& square : squares){
                double l = square[2], y = square[1];
                area_y += l * min(max(yc - y, 0.0), l);
            }

            if(area_y >= half_area){
                R = yc;
            }
            else{
                L = yc;
            }
        }

        return (L + R) / 2;
    }
};