class Solution {
public:
    // bool rec(int n, bool cur) {
    //     if (!n) return cur;
    //     int &ret = dp[n][cur];
    //     if (~ret) return ret;
    //     ret = cur;
    //     for (int j = 1; j * j <= n; ++j) {
    //         if (cur == 0) ret |= dp[n - j * j];
    //         else ret &= dp[n - j * j]; 
    //     }
    //     return ret;
    // }
    bool winnerSquareGame(int n) {
        vector<vector<short>> dp(n + 1, vector<short>(2));
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int cur = 0; cur < 2; ++cur) {
                dp[i][cur] = cur;
                for (int k = 1; k * k <= i; ++k) {
                    if (cur == 0) dp[i][cur] |= dp[i - k * k][!cur];
                    else dp[i][cur] &= dp[i - k * k][!cur];
                }
            }
        }
        return dp[n][0];
    }
};