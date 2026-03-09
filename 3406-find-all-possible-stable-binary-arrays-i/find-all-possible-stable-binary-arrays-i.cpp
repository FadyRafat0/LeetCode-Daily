class Solution {
int const mod = 1e9 + 7;
int const static N = 201;
int dp[N][N][N][2], limit;
public:
    int rec(int o, int z, int cnt, bool lst) {
        if (cnt < 0) return 0;
        if (!o && !z) return 1;
        int &ret = dp[o][z][cnt][lst];
        if (~ret) return ret;

        ret = 0;

        if (o) {
            ret = (ret + rec(o - 1, z, (lst == 1 ? cnt - 1 : limit - 1), 1)) % mod;
        }
        if (z) {
            ret = (ret + rec(o, z - 1, (lst == 0 ? cnt - 1 : limit - 1), 0)) % mod;
        }
        return ret;
    }
    // one , zero , cnt , 2
    int numberOfStableArrays(int zero, int one, int limit) {
        // any continous zeros of limit or one
        // memset(dp, -1, sizeof dp);

        dp[0][1][1][0] = 1; 
        dp[1][0][1][1] = 1;        
        // for (int i = 0; i <= limit; ++i) {
        //     for (int j = 0; j < 2; ++j) {
        //         dp[0][0][i][j] = 1;
        //     }
        // }

        for (int o = 0; o <= one; ++o) {
            for (int z = 0; z <= zero; ++z) {
                for (int cnt = 0; cnt <= limit; ++cnt) {
                    for (int lst = 0; lst < 2; ++lst) {
                        int &ret = dp[o][z][cnt][lst];
                        int cur = (lst == 0 ? cnt + 1 : 1);
                        if (z < zero && cur <= limit) {
                            dp[o][z + 1][cur][0] += ret;
                            if (dp[o][z + 1][cur][0] >= mod)
                                dp[o][z + 1][cur][0] -= mod;
                        }
                        
                        cur = (lst == 1 ? cnt + 1 : 1);
                        if (o < one && cur <= limit) {
                            dp[o + 1][z][cur][1] += ret;
                            if (dp[o + 1][z][cur][1] >= mod)
                                dp[o + 1][z][cur][1] -= mod;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int cnt = 0; cnt <= limit; ++cnt) {
            for (int lst = 0; lst < 2; ++lst) {
                ans = (ans + dp[one][zero][cnt][lst]) % mod;
            }
        }
        
        return ans;
    }
};