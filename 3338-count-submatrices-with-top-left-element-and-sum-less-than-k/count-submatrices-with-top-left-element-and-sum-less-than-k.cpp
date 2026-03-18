class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prf(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prf[i][j] = prf[i - 1][j] + prf[i][j - 1] - prf[i - 1][j - 1] + grid[i - 1][j - 1];

                if (prf[i][j] <= k) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};