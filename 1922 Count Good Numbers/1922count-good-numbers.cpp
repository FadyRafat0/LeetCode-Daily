class Solution {
public:
    int const mod = 1e9 + 7;
    long long fp(long long b, long long e) {
        if (!e) return 1;
        long long rs = fp(b, e / 2);
        rs = ((rs % mod) * (rs % mod)) % mod;
        return (e & 1 ? (rs * (b % mod)) : rs) % mod;
    }
    int countGoodNumbers(long long n) {
        // ev positions -> 5^(n+1)/2 * 4^(n/2)
        return ((fp(5, (n+1)/2) % mod) * (fp(4, n / 2) % mod)) % mod;
    }
};