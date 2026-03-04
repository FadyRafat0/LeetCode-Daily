class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 0));

        vector<int> one_row(n), one_col(m), zero_row(n), zero_col(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                one_row[i] += grid[i][j];
                zero_row[i] += !grid[i][j];
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                one_col[j] += grid[i][j];
                zero_col[j] += !grid[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diff[i][j] = one_row[i] + one_col[j] - zero_row[i] - zero_col[j];
            }
        }

        return diff;
    }
};