class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prf_X(n + 1, vector<int>(m + 1));
        auto prf_Y = prf_X;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prf_X[i][j] = prf_X[i - 1][j] + prf_X[i][j - 1] - prf_X[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X');
                prf_Y[i][j] = prf_Y[i - 1][j] + prf_Y[i][j - 1] - prf_Y[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y');

                if (prf_X[i][j] && prf_X[i][j] == prf_Y[i][j]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};