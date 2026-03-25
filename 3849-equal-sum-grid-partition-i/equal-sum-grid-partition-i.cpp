class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> prf_row(n + 1), prf_col(m + 1); 
        for (int i = 1; i <= n; ++i) {
            prf_row[i] = prf_row[i - 1];
            for (int j = 0; j < m; ++j) {
                prf_row[i] += grid[i - 1][j];
            }
        }
        for (int j = 1; j <= m; ++j) {
            prf_col[j] = prf_col[j - 1];
            for (int i = 0; i < n; ++i) {
                prf_col[j] += grid[i][j - 1];
            }
        }

        for (int i = 1; i < n; ++i) {
            if (2 * prf_row[i] == prf_row[n])
                return 1;
        }
        for (int j = 1; j < m; ++j) {
            if (2 * prf_col[j] == prf_col[m]) 
                return 1;
        }

        return 0;
    }
};