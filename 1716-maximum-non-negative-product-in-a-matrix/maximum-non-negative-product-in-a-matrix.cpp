#define ll long long
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        // maximum non negative product
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<ll>>> dis(n, vector<vector<ll>>(m, vector<ll>(2, -1e18)));
        
        priority_queue<tuple<ll, int, int, int>> pq;
        dis[0][0][grid[0][0] >= 0] = grid[0][0];
        pq.push({abs(grid[0][0]), (grid[0][0] >= 0), 0, 0});

        while (pq.size()) {
            auto [cost, sgn, x, y] = pq.top();
            pq.pop();

            if (dis[x][y][sgn] > cost) continue;

            if (!sgn)
                cost = -cost;

            ll nw_cost;
            int nw_sgn;
            if (x + 1 < n) {
                nw_cost = cost * grid[x + 1][y];
                nw_sgn = (nw_cost >= 0);
                nw_cost = abs(nw_cost); 
                if (dis[x + 1][y][nw_sgn] < nw_cost) {
                    dis[x + 1][y][nw_sgn] = nw_cost;
                    pq.push({nw_cost, nw_sgn, x + 1, y});
                }
            }

            if (y + 1 < m) {
                nw_cost = cost * grid[x][y + 1];
                nw_sgn = (nw_cost >= 0);
                nw_cost = abs(nw_cost);
                if (dis[x][y + 1][nw_sgn] < nw_cost) {
                    dis[x][y + 1][nw_sgn] = nw_cost;
                    pq.push({nw_cost, nw_sgn, x, y + 1});
                }
            }
        }
        
        bool zero = 0;
        for (auto &i : grid) for (auto &j : i) zero |= (j == 0);

        ll ans = dis[n - 1][m - 1][1];
        if (ans < 0) ans = (zero ? 0 : -1);
        else ans %= (int)1e9 + 7;
        return ans;
    }
};