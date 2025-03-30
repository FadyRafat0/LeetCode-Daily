class Solution {
public:
    int static const N = 1e3;
    int dp[N][N];
    string a, b;
    int rec(int l, int r) {
        if (r >= b.size()) return 1;
        if (l >= a.size()) return 0;
        int &ret = dp[l][r];
        if (~ret) return ret;
        return ret = rec(l + 1, r) + (a[l] == b[r] ? rec(l + 1, r + 1) : 0);
    }
    int numDistinct(string s, string t) {
        a = s, b = t;
        memset(dp, -1, sizeof dp);
        return rec(0, 0);
    }
};