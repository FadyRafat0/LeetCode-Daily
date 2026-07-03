class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> g(n);
        vector<int> in(n);
        for (auto &x : edges) {
            int u = x[0], v = x[1], c = x[2];
            if (!online[u] || !online[v]) continue;
            g[u].emplace_back(v, c);
            in[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!in[i]) q.push(i);
        }

        vector<int> order;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            order.push_back(u);
            for (auto &[v, c] : g[u]) {
                in[v]--;
                if (!in[v]) q.push(v);
            }
        }
    
        int st = 0, en = 1e9, md, ans = -1;
        while (st <= en) {
            md = (st + en) / 2;
            vector<long long> dp(n, 1e18);
            dp[0] = 0;
            for (auto &u : order) {
                for (auto &[v, c] : g[u]) {
                    if (c < md) continue;
                    dp[v] = min(dp[v], dp[u] + c);
                }
            }

            if (dp[n - 1] <= k) st = md + 1, ans = md;
            else en = md - 1;
        }
        
        return ans;
    }
};