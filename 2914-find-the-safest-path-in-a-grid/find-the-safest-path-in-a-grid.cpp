class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // i want path and get it's Min Value (binary search)
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) q.push({i, j}), dis[i][j] = 0;
            }
        }

        vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

        auto valid = [&](int x, int y) {
            return (x >= 0 && x < n && y >= 0 && y < n);
        };

        while (q.size()) {
            auto [x,y] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (valid(nx, ny) && dis[nx][ny] == 1e9) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
             }
        }

        int st = 0, en = dis[0][0], md, ans = 0;
        while (st <= en) {
            md = (st + en) / 2;
            queue<pair<int, int>> go;
            vector<vector<bool>> reach(n, vector<bool>(n, 0));
            reach[0][0] = 1;
            go.push({0, 0});

            while (go.size()) {
                auto [x,y] = go.front();
                go.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (valid(nx, ny) && reach[nx][ny] == 0 && dis[nx][ny] >= md) {
                        go.push({nx, ny});
                        reach[nx][ny] = 1;
                    }
                }
            }

            // cout << "For " << md << " : \n";
            // for (int i = 0; i < n; ++i) {
            //     for (int j = 0; j < n; ++j) {
            //         cout << reach[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }

            if (reach[n - 1][n - 1]) st = md + 1, ans = md;
            else en = md - 1;
        }

        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dis[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        return ans;
    }
};