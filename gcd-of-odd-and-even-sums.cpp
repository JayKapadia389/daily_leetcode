// Solution 1:
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n, sumEven = n*(n+1);
        return gcd(sumOdd, sumEven);
    }
};

// Solution 2:
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};