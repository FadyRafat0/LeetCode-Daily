class Solution {
public:
    int const mod = 12345;
    int mul(int a, int b) {
        return (1ll * a * b) % mod;
    }
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prf(n + 3, 1), suf(n + 3, 1);
        for (int i = 1; i <= n; ++i) {
            int x = 1;
            for (int j = 1; j <= m; ++j) {
                x = mul(x, grid[i - 1][j - 1]);
            }
            prf[i] = mul(prf[i - 1], x);
        }
        for (int i = n; i >= 1; --i) {
            int x = 1;
            for (int j = 1; j <= m; ++j) {
                x = mul(x, grid[i - 1][j - 1]);
            }
            suf[i] = mul(suf[i + 1], x);
        }

        vector<vector<int>> ans(n, vector<int>(m));
        vector<int> cur_prf(m + 2, 1), cur_suf(m + 2, 1);
        for (int i = 1; i <= n; ++i) {
            int cur = mul(prf[i - 1], suf[i + 1]);
            for (int j = 1; j <= m; ++j) {
                cur_prf[j] = mul(cur_prf[j - 1], grid[i - 1][j - 1]);
            }
            for (int j = m; j >= 1; --j) {
                cur_suf[j] = mul(cur_suf[j + 1], grid[i - 1][j - 1]);
            }

            for (int j = 1; j <= m; ++j) {
                ans[i - 1][j - 1] = mul(cur, mul(cur_prf[j - 1], cur_suf[j + 1]));
            }
        }

        return ans;
    }
};