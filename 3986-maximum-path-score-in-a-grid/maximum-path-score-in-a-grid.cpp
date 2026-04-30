int dp[200][200][1001];

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) for (int x = 0; x <= k; ++x)
            dp[i][j][x] = -1e9;

        dp[0][0][k - (grid[0][0] > 0)] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int x = 0; x <= k; ++x) {
                    if (dp[i][j][x] == -1e9) continue;

                    if (i + 1 < n) {
                        int a = (x - (grid[i + 1][j] > 0));
                        if (a >= 0)
                            dp[i + 1][j][a] = max(dp[i + 1][j][a], dp[i][j][x] + grid[i + 1][j]);
                    }
                    if (j + 1 < m) {
                        int a = (x - (grid[i][j + 1] > 0));
                        if (a >= 0)
                            dp[i][j + 1][a] = max(dp[i][j + 1][a], dp[i][j][x] + grid[i][j + 1]);
                    }
                }
            }
        }

        int ans = -1e9;
        for (int x = 0; x <= k; ++x) ans = max(ans, dp[n - 1][m - 1][x]);
        if (ans < 0) return -1;
        return ans;
    }
};