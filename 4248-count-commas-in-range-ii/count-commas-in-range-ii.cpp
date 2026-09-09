class Solution {
public:

    int static const N = 18;
    long long dp[N][N][2][2];
    string s;
    long long rec(int i, int cnt, bool st, bool up) {
        if (cnt < 0) return 0;
        if (i == N) return (cnt == 0);
        long long &ret = dp[i][cnt][st][up];
        if (~ret) return ret;
        ret = 0;
        int en = (up ? s[i] - '0' : 9);
        for (int d = 0; d <= en; ++d) {
            ret += rec(i + 1, cnt - (d != 0 || st), st || (d != 0), (up && d == en));
        }
        return ret;
    }
    long long countCommas(long long n) {
        // (count - 1) / 3
        // [1, n]
        s = to_string(n);
        while (s.size() < N) s = "0" + s;
        memset(dp, -1, sizeof dp);
        long long ans = 0;
        for (int cnt = 1; cnt < N; ++cnt) {
            cout << cnt << ' '  << rec(0, cnt, 0, 1) << '\n';
            ans += (cnt - 1) / 3 * rec(0, cnt, 0, 1);
        }
        return ans;
    }
};