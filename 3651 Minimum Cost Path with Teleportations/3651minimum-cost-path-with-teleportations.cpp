class Solution {
private:
    vector<vector<int>> dis;
    int n, m;

    int dx[2] = {-1, 0};
    int dy[2] = {0, -1};

    bool valid(int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
public:
    
    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dis = vector<vector<int>>(n, vector<int>(m, 1e9));
        dis[0][0] = 0;

        vector<array<int, 3>> srt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                srt.push_back({grid[i][j], i, j});
            }
        }

        sort(srt.begin(), srt.end(), greater<>());

        vector<vector<int>> idx(dis);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                array<int, 3> arr = {grid[i][j], -1, -1};
                auto it = upper_bound(srt.begin(), srt.end(), arr, greater<>()) - srt.begin() - 1;
                idx[i][j] = it;
                cout << idx[i][j] << ' ';
            }
            cout << "\n";
        }

        for (int x = 0; x <= k; x++) {
            vector<vector<int>> nw_dis = dis;
            vector<int> prf_mn(srt.size(), 1e9);
            for (int i = 0; i < srt.size(); i++) {
                if (i > 0) prf_mn[i] = prf_mn[i - 1];
                prf_mn[i] = min(prf_mn[i], dis[srt[i][1]][srt[i][2]]);
            }

            if (x) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        nw_dis[i][j] = min(nw_dis[i][j], prf_mn[idx[i][j]]);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    for (int k = 0; k < 2; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (valid(nx, ny)) {
                            nw_dis[i][j] = min(nw_dis[i][j], nw_dis[nx][ny] + grid[i][j]);
                        }
                    }
                }
            }
            dis = nw_dis;
        }

        return dis[n - 1][m - 1];
    }
};