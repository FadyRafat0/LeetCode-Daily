class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n + 1,   
                                    vector<vector<int>>(m + 1, 
                                    vector<int>(3, -1e9)));

        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = dp[0][0][2] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int op = 0; op < 3; ++op) {
                    for (int k = 0; k < 2; ++k) {
                        int x = i + dx[k], y = j + dy[k];

                        if (x >= n || y >= m) continue;

                        dp[x][y][op] = max(dp[x][y][op], dp[i][j][op] + coins[x][y]);
                        if (op < 2) {
                            dp[x][y][op + 1] = max(dp[x][y][op + 1], dp[i][j][op]);
                        } 
                    }
                }
            }
        }

        int ans = *max_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
        return ans;
    }
};