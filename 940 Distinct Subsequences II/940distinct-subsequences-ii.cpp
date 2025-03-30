#define ll long long
class Solution {
public:
    ll static const N = 2e3 + 5, mod = 1e9 + 7;
    ll add(ll a, ll b) { return (a + b + mod) % mod; }
    ll dp[N], nxt[N][26], n;
    ll rec(int i) {
        if (i >= n) return 0;
        ll& ret = dp[i];
        if (~ret) return ret;
        ret = 0;
        for (int j = 0; j < 26; ++j) {
            if (nxt[i + 1][j] != -1)
                ret = add(ret, add(rec(nxt[i + 1][j]), 1));
        }
        return ret;
    }
    ll distinctSubseqII(string s) {
        memset(dp, -1, sizeof dp);
        memset(nxt, -1, sizeof nxt);
        n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                nxt[i][j] = nxt[i + 1][j];
                if (s[i] - 'a' == j)
                    nxt[i][j] = i;
            }
        }
        ll ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (nxt[0][i] != -1)
                ans = add(ans, add(rec(nxt[0][i]), 1));
        }
        return ans;
    }
};