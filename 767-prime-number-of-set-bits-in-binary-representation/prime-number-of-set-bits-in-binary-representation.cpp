class Solution {
public:
    bool is_prime(int x) {
        if (x == 1) return 0;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) return 0;
        }
        return 1;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            int cnt = __builtin_popcount(i);
            ans += is_prime(cnt);
        }
        return ans;
    }
};