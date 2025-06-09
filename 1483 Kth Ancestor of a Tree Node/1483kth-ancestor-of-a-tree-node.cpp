class TreeAncestor {
public:
    int static const N = 5e4 + 5;
    vector<int> adj[N];
    int par[N][32];
    void dfs(int u, int p) {
        par[u][0] = p;
        for (int j = 1; j < 32; ++j) {
            if (par[u][j - 1] == -1) break;
            par[u][j] = par[par[u][j - 1]][j - 1];
        }

        for (auto &v : adj[u]) {
            dfs(v, u);
        }
    }
    TreeAncestor(int n, vector<int>& parent) {   
        memset(par, -1, sizeof par);
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) continue;
            adj[parent[i]].push_back(i);
        }
        dfs(0, -1);
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 31; i >= 0; --i) {
            if (k & (1ll << i)) {
                node = par[node][i];
                if (node == -1)
                    return node;
            }
        }
        return node;
     }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */