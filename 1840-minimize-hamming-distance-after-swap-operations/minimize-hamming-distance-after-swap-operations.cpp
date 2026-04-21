class Solution {
public:
    vector<int> cur;
    void dfs(int u, vector<vector<int>> &adj, vector<int> &cur, vector<bool> &vis) {
        vis[u] = 1;
        cur.push_back(u);
        for (auto &v : adj[u]) {
            if (vis[v]) continue;
            dfs(v, adj, cur, vis);
        }
    }
    int minimumHammingDistance(vector<int>& a, vector<int>& b, vector<vector<int>>& c) {
        int n = a.size();
        vector<vector<int>> adj(n);
        for (auto &v : c) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }

        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            vector<int> cur;
            dfs(i, adj, cur, vis);

            multiset<int> st;
            for (auto &idx : cur) {
                st.insert(a[idx]);
            }
            for (auto &idx : cur) {
                st.extract(b[idx]);
            }

            ans += st.size();
        }

        return ans;
    }
};