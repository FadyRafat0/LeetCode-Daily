class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); ++i) {
            mp[arr[i]].emplace_back(i);
        }

        vector<int> dis(arr.size(), 1e9);
        queue<int> q;
        q.push(0);
        dis[0] = 0;

        while (q.size()) {
            auto u = q.front();
            q.pop();
            vector<int> cur = mp[arr[u]];
            if (u > 0) cur.emplace_back(u - 1);
            if (u + 1 < arr.size()) cur.emplace_back(u + 1);
        
            for (auto &v : cur) {
                if (dis[v] == 1e9) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }

            mp[arr[u]].clear();
        }
        
        return dis[arr.size() - 1];
    }
};