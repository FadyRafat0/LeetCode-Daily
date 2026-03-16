class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> sums;
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                sums.push_back(grid[i][j]);
                for (int sz = 1; i - sz >= 0 && i + sz < n && j - sz >= 0 && j + sz < m; ++sz) {
                
                    int sum = 0;
                    int x = i - sz, y = j;
                    while (x < i) sum += grid[x][y], ++x, ++y;

                    while (x < i + sz) sum += grid[x][y], ++x, --y;

                    while (x > i) sum += grid[x][y], --x, --y;

                    while (x > i - sz) sum += grid[x][y], --x, ++y;

                    sums.push_back(sum);
                }
            }
        }

        sort(sums.begin(), sums.end(), greater<>());
        sums.erase(unique(sums.begin(), sums.end()), sums.end());

        vector<int> ret;
        for (int i = 0; i < min((int)sums.size(), 3); ++i)
            ret.push_back(sums[i]);

        return ret;
    }
};