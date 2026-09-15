class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, 0));
        for (int l = n - 1; l >= 0; --l) {
            for (int r = l; r < n; ++r) {
                if (s[l] == s[r])
                    pal[l][r] = (r - l <= 1 ? 1 : pal[l + 1][r - 1]);
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = i; j < n; ++j) {
        //         cout << i << ", " << j << " : " << pal[i][j] << '\n';
        //     } 
        // }

        vector<int> dp2(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            dp2[i] = dp2[i + 1];
            for (int j = i + k - 1; j < n; ++j) {
                if (!pal[i][j]) continue;
                dp2[i] = max(dp2[i], dp2[j + 1] + 1);
            }
        }

        // cout << pal[5][8] << '\n';
        // for (auto &i : dp2) cout << i << ' ';
        // cout << '\n';

        return dp2[0];
    }
};