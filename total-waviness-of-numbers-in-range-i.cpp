class Solution {
private:
int compute_waviness(int num) {
    vector<int> arr;
    int waviness = 0;
    
    while(num != 0){
        arr.push_back(num % 10);
        num /= 10;
    }

    for(int i = 1; i < arr.size() - 1; ++i){
        if((arr[i] < arr[i-1] && arr[i] < arr[i+1]) || (arr[i] > arr[i-1] && arr[i] > arr[i+1])){
            ++waviness;
        }
    }

    return waviness;
}

public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;

        for(int i = num1; i <= num2; ++i){
            total_waviness += compute_waviness(i);
        }

        return total_waviness;
    }
};