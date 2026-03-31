class Solution {
public:
    vector<int> pi_function(string s) {
        int n = s.size();
        vector<int> pi(n);
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            pi[i] = j;
        }
        return pi;
    }
    vector<vector<int>> compute_automaton(string s) {
        s += '$';
        int n = (int)s.size();
        vector<vector<int>> aut(n + 1, vector<int>(26));
        auto pi = pi_function(s);
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (i > 0 && 'a' + c != s[i]) aut[i][c] = aut[pi[i - 1]][c];
                else aut[i][c] = i + ('a'  + c == s[i]);
            }
        }
        return aut;
    }

    vector<vector<int>> dp, aut;
    string s, t;
    int n, m;
    int rec(int i, int j) {
        if (i >= m) {
            if (s[i - m] == 'T') {
                if (j != m) return 0;
            }
            else {
                if (j == m) return 0;
            }
        }

        if (i == n + m - 1) return 1;
        int &ret = dp[i][j];
        if (~ret) return ret;
        ret = 0;

        for (int c = 0; c < 26; ++c) {
            if (rec(i + 1, aut[j][c])) {
                ret = 1;
                break;
            }
        }

        return ret;
    }
    void build(int i, int j, string &ans) {
        if (i == n + m - 1) return;
        for (int c = 0; c < 26; ++c) {
            if (rec(i + 1, aut[j][c])) {
                ans += c + 'a';
                build(i + 1, aut[j][c], ans);
                return;
            }
        }
    }

    string generateString(string str1, string str2) {
        s = str1, t = str2;
        n = s.size(), m = t.size();

        dp = vector<vector<int>>(n + m + 1, vector<int>(m + 1, -1));

        aut = compute_automaton(t);

        if (!rec(0, 0))
            return "";
        string ans;
        build(0, 0, ans);
        return ans;
    }
};