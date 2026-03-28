class Solution {
public:
    vector<vector<int>> dp;
    int rec(int i, int j, string &s) {
        if (max(i, j) >= s.size()) return 0;
        int &ret = dp[i][j];
        if (~ret) return ret;
        ret = (s[i] == s[j] ? rec(i + 1, j + 1, s) + 1 : 0);
        return ret;
    }
    string findTheString(vector<vector<int>>& lcp) {        
        int n = lcp.size();
        string s(n, '0');
        for (int i = 0; i < n; ++i) {
            vector<bool> vis(26);
            for (int j = 0; j < i; ++j) {
                if (lcp[i][j]) {
                    s[i] = s[j];
                    break;
                }
                else {
                    vis[s[j] - 'a'] = 1;
                }
            }

            if (s[i] != '0') continue;
            int ch = -1;
            for (int j = 0; j < 26; ++j) {
                if (!vis[j]) {
                    ch = j; break;
                }
            }

            if (ch == -1) return "";

            s[i] = ch + 'a';
        }

        dp = vector<vector<int>>(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int real = rec(i, j, s);
                if (real != lcp[i][j]) return "";
            }
        }

        return s;
    }
};