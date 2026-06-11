class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // dp[i + 1] += dp[i], dp[i + 2] += dp[i]
        int n = edges.size() + 1;
        vector<int> adj[n + 1];
        for (auto &vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        } 
        vector<int> dis(n + 1, -1);
        queue<int> q;
        dis[1] = 0;
        q.push(1);
        int mx = -1;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            mx = max(mx, dis[u]);
            for (auto &v : adj[u]) {
                if (dis[v] == -1)
                    dis[v] = dis[u] + 1, q.push(v);
            }
        }

        int ans = 1;
        for (int i = 1; i < mx; i++) {
            ans *= 2;
            ans %= (int)1e9 + 7;
        }
        return ans;
    }
};