class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            if (vis[i][j]) continue;

            queue<pair<int, int>> q;
            q.push({i, j});

            vis[i][j] = 1;
            par[i][j] = {-1, -1};

            while (q.size()) {
                auto [x, y] = q.front();
                q.pop(); 
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[x][y] == grid[nx][ny]) {
                        if (vis[nx][ny]) {
                            if (par[x][y] != pair<int, int>{nx, ny})
                                return true;
                            continue;
                        }

                        par[nx][ny] = {x, y};
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return false;
    }
};