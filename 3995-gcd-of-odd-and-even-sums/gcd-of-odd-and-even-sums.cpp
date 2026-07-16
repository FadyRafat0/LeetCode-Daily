class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = 0, b = 0;
        for (int i = 1; i <= n; ++i) {
            a += i * 2 - 1;
            b += i * 2;
        } 
        return gcd(a, b);
    }
};