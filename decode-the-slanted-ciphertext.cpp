class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText == ""){
            return "";
        }

        int m = rows, size = encodedText.size();
        int n = size / m;
        vector<vector<char>> matrix(m, vector<char>(n));

        for(int i = 0; i < size; ++i){
            matrix[i/n][i%n] = encodedText[i];
        }

        string originalText = "";
        originalText.reserve(size);

        for(int j = 0; j < n; ++j){
            for(int i = 0; i < m; ++i){
                if((j + i) >= n){
                    continue;
                }
                originalText += matrix[i][j+i];
            }
        }

        while(originalText.back() == ' '){
            originalText.pop_back();
        }
        return originalText;
    }
};