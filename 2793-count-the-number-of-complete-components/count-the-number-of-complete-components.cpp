class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<bool> vis(n, 0);
        for (int u = 0; u < n; ++u) {
            if (vis[u]) continue;
            vis[u] = 1;
            queue<int> q;
            q.push(u);

            vector<int> comp;
            while (q.size()) {
                auto u = q.front();
                q.pop();
                comp.push_back(u);
                for (auto &v : adj[u]) {
                    if (vis[v]) continue;
                    vis[v] = 1;
                    q.push(v);
                }
            }

            bool ok = 1;
            for (auto &u : comp) {
                ok &= (adj[u].size() == comp.size() - 1);
            }

            ans += ok;
        }

        return ans;
    }
};