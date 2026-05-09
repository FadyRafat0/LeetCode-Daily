class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = 0;
        vector<vector<int>> ans(grid);
        while (i < n / 2 & j < m / 2) {
            vector<pair<int, int>> idxs;
            int x = i, y = j;
            while (x < n - i - 1) idxs.emplace_back(x++, y);
            while (y < m - j - 1) idxs.emplace_back(x, y++);
            while (x > i) idxs.emplace_back(x--, y);
            while (y > j) idxs.emplace_back(x, y--);

            int cur = k % idxs.size();
            for (int i = 0; i < idxs.size(); ++i) {
                auto [x, y] = idxs[i];
                auto [x2, y2] = idxs[(i - cur + idxs.size()) % (int)idxs.size()];
                ans[x][y] = grid[x2][y2];
            }

            ++i, ++j;
        }

        return ans;
    }
};