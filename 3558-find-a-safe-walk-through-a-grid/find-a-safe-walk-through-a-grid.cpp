class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

        auto valid = [&](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < m);
        };

        deque<pair<int, int>> dq;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        dis[0][0] = grid[0][0];
        dq.push_back({0, 0});

        while (dq.size()) {
            auto [x,y] = dq.front();
            dq.pop_front();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (valid(nx, ny) && dis[nx][ny] == 1e9) {
                    dis[nx][ny] = dis[x][y] + grid[nx][ny];
                    if (grid[nx][ny]) dq.push_back({nx, ny});
                    else dq.push_front({nx, ny});
                }
            }
        }
        return (health > dis[n - 1][m - 1]);
    }
};