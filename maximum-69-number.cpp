class Solution {
public:
    int maximum69Number (int num) {
        string num_str = to_string(num);
        size_t pos = num_str.find("6");

        if(pos == std::string::npos){
            return num;
        }

        num_str[pos] = '9';
        return stoi(num_str);
    }
};