class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n + 1);
        for (auto &x : roads) {
            int u = x[0], v = x[1], d = x[2];
            g[u].emplace_back(v, d);
            g[v].emplace_back(u, d);
        }

        vector<int> dis(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({1e9, 1});

        while (pq.size()) {
            auto [cost, u] = pq.top();
            pq.pop();
            if (dis[u] < cost) continue;
            for (auto &[v,d] : g[u]) {
                int new_cost = min(cost, d);
                if (dis[v] > new_cost) {
                    dis[v] = new_cost;
                    pq.push({dis[v], v});
                } 
            }
        }

        return dis[n];
    }
};