class Solution {
int const mod = 1e9 + 7;
int add(long long a, int b) {
    return (a + b + mod) % mod;
}
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));
        for (int i = 1; i <= min(zero, limit); ++i) dp[i][0][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp[0][j][1] = 1;

        for (int o = 1; o <= one; ++o) {
            for (int z = 1; z <= zero; ++z) {
                {
                    int &ret = dp[z][o][0];
                    ret = add(dp[z - 1][o][0], dp[z - 1][o][1]) % mod;
                    if (z > limit) {
                        ret = add(ret, -dp[z - limit - 1][o][1]);
                    }
                }

                {
                    int &ret = dp[z][o][1];
                    ret = add(dp[z][o - 1][0], dp[z][o - 1][1]);
                    if (o > limit) {
                        ret = add(ret, -dp[z][o - limit - 1][0]);
                    }
                }
            }
        }

        int ans = add(dp[zero][one][0], dp[zero][one][1]);
        return ans;
    }
};