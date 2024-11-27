class Solution {
public:
    int dfs(int n, vector<int> adj[])
    {
        vector<int> dis(n, 1e9);
        dis[0] = 0;
        queue<int> q;
        q.push(0);

        while (q.size())
        {
            int u = q.front();
            q.pop();
            
            for (auto &v : adj[u]){
                if (dis[v] == 1e9)
                    dis[v] = dis[u] + 1, q.push(v);
            }
        }
        return dis[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int const N = 500;
        vector<int> adj[N];
        for (int i = 0; i < n - 1; ++i)
            adj[i].push_back(i + 1);
        vector<int> res;
        for (auto v : queries)
        {
            adj[v[0]].push_back(v[1]);
            res.push_back(dfs(n, adj));
        }
        return res;
    }
};