struct DSU {
    vector<int> par, sz;
    DSU(int n) {
        par = sz = vector<int>(n+5);
        for (int i = 0; i <= n; ++i)
            par[i] = i, sz[i] = 1;
    }
    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u, sz[u] += sz[v];
    }
    bool con(int u, int v) {
        return (find(u) == find(v));
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        for (int i = 0; i < edges.size(); ++i) {
            int &u = edges[i][0];
            int &v = edges[i][1];

            if (edges[i][3]) {
                if (dsu.con(u, v)) {
                    return -1;
                }
                dsu.merge(u, v);
            }
        }

        sort(edges.begin(), edges.end(), [&](vector<int> &a, vector<int> &b) {
            return a[2] > b[2];
        });

        vector<int> all_edges;
        int mn = 1e9;
        for (int i = 0; i < edges.size(); ++i) {
            int &u = edges[i][0];
            int &v = edges[i][1];

            if (edges[i][3]) {
                mn = min(mn, edges[i][2]);
            }
            if (edges[i][3] || dsu.con(u, v)) continue; 

            dsu.merge(u, v);
            all_edges.push_back(edges[i][2]);
        }

        sort(all_edges.begin(), all_edges.end());
        for (int i = 0; i < min((int)all_edges.size(), k); ++i) {
            all_edges[i] *= 2;
        }

        if (dsu.sz[dsu.find(1)] != n) {
            return -1;
        }

        if (all_edges.size()) {
            mn = min(mn, *min_element(all_edges.begin(), all_edges.end()));
        }
        return mn;
    }
};