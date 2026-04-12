class Solution {
public:
    int static const N = 305;
    int dp[N][26][26];
    pair<int, int> pos[26];
    string s;
    int dis(pair<int, int> a, pair<int, int> b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }
    int rec(int i, int a, int b) {
        if (i == s.size()) return 0;
        int &ret = dp[i][a][b];
        if (~ret) return ret;
        int L = rec(i + 1, s[i] - 'A', b) + dis(pos[s[i] - 'A'], pos[a]);
        int R = rec(i + 1, a, s[i] - 'A') + dis(pos[s[i] - 'A'], pos[b]);
        return ret = min(L, R);
    }
    int minimumDistance(string word) {
        for (int i = 0; i < 26; ++i) {
            pos[i] = {i / 6, i % 6};
        }
        this->s = word;
        memset(dp, -1, sizeof dp);
        int ans = 1e9;
        for (int a = 0; a < 26; ++a) {
            ans = min(ans, rec(0, s[0] - 'A', a));
        }
        return ans;
    }
};