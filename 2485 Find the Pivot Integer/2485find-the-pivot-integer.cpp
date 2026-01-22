class Solution {
public:
    int pivotInteger(int n) {
        int sum = n * (n + 1) / 2;
        int sq = sqrt(sum);
        return (sq * sq == sum ? sq : -1);
        // x ^ 2 = n * (n + 1) / 2
    }
};