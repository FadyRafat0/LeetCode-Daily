class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        vector<int> dis(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, 0});
        dis[0] = 0;

        while (pq.size()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) continue;
            for (auto &[v, w] : adj[u]) {
                if (d + w < dis[v]) {
                    dis[v] = d + w;
                    pq.push({dis[v], v});
                }
            }
        }
        return (dis[n - 1] == 1e9 ? -1 : dis[n - 1]);
    }
};