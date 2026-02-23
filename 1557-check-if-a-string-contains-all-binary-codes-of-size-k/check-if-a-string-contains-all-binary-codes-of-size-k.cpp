class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> vis(1<<k + 5, 0);
        int n = s.size();
        for (int i = 0; i + k - 1 < n; ++i) {
            int cur = 0, d = (1 << (k - 1));
            for (int j = i; j < i + k; ++j) {
                if (s[j] == '1')
                    cur |= d;
                d >>= 1;
            }
            // cout << cur << ' ';
            vis[cur] = 1;
        }
        // cout << '\n';

        for (int i = 0; i < (1 << k); ++i) {
            if (!vis[i])
                return 0;
        }
        return 1;
    }
};