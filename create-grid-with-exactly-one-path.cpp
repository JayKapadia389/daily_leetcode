class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid;

        // top row
        string top = "";
        top.reserve(n);
        
        for(int i = 0; i < n; ++i){
            top += '.';
        }
        grid.push_back(top);

        // rest of the rows
        string rest = "";
        rest.reserve(n);
        
        for(int i = 0; i < n; ++i){
            rest += '#';
        }
        
        rest[n-1] = '.';
        
        for(int i = 0; i < m - 1; ++i){
            grid.push_back(rest);
        }

        return grid;
    }
};