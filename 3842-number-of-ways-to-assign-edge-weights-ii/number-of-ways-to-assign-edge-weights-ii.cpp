class Solution {
public:
    int static const N = 2e5 + 5, M = 20;
    int par[N][M], lvl[N];
    vector<int> adj[N];
    void build(int u, int p) {
        par[u][0] = p;
        for (int i = 1; i < M; ++i)
            par[u][i] = par[par[u][i - 1]][i - 1];

        for (auto &v : adj[u]) {
            if (v == p) continue;
            lvl[v] = lvl[u] + 1;
            build(v, u);
        }
    }
    int kth(int u, int k) {
        for (int i = M - 1; i >= 0; --i)
            if (k & (1 << i))
                u = par[u][i];
        return u;
    }
    int lca(int u, int v) {
        if (lvl[u] < lvl[v])
            swap(u, v);
        u = kth(u, lvl[u] - lvl[v]);
        if (u == v) return u;
        for (int i = M - 1; i >= 0; --i)
            if (par[u][i] != par[v][i])
                u = par[u][i], v = par[v][i];
        return par[u][0];
    }
    int dis(int u, int v) {
        return lvl[u] + lvl[v] - 2 * lvl[lca(u, v)];
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        for (auto &vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        build(1, 0);

        vector<int> pw(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; ++i) pw[i] = (pw[i - 1] * 2) % (int)(1e9 + 7);

        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0], v = queries[i][1];
            if (u == v) ans.emplace_back(0);
            else ans.emplace_back(pw[dis(u, v) - 1]);
        }
        return ans;
   }
};