class Solution {
public:
    int concatenatedBinary(int n) {
        // 6 * [10^5]
        long long ans = 0, pw = 1, mod = 1e9 + 7;
        for (int i = n; i >= 1; --i) {
            int x = i;
            while (x > 0) {
                int d = x % 2;

                ans = (ans + d * pw) % mod;

                pw = (pw * 2) % mod;
                x /= 2;
            }
        }

        // cout << ans << '\n';
        return ans;
    }
};