#define ll long long
#define inf 1e15

struct Trie {
    struct Node {
        int vis[26]{}, id = -1;
    };
    int cur_id = 0;
    vector<Node> tree;
    Trie() { tree.emplace_back(); }
    void insert(string s) {
        int idx = 0;
        for (auto &i : s) {
            int c = i - 'a';
            if (!tree[idx].vis[c]) {
                tree[idx].vis[c] = tree.size();
                tree.emplace_back();
            }
            idx = tree[idx].vis[c];
        }
        if (tree[idx].id == -1)
            tree[idx].id = cur_id++;
    }
    int get_id(string s) {
        int idx = 0;
        for (auto &c : s) {
            idx = tree[idx].vis[c - 'a'];
        }
        return tree[idx].id;
    }
    int nxt(int idx, char c) {
        if (tree[idx].vis[c - 'a'] == 0) return -1;
        return tree[idx].vis[c - 'a'];
    }
};

class Solution {
private:
    vector<ll> dp;
    vector<vector<ll>> dis;
    int n;
    string s, t;
    Trie tr;

    ll rec(int i) {
        if (i == n) return 0;
        ll &ret = dp[i];
        if (ret != -1) return ret; 
        ret = inf;
        if (s[i] == t[i])
            ret = rec(i + 1);
        int u = 0, v = 0;
        for (int j = i; j < n; j++) {
            u = tr.nxt(u, s[j]);
            v = tr.nxt(v, t[j]);
            if (u < 0 || v < 0) break;
            int id_u = tr.tree[u].id, id_v = tr.tree[v].id;
            if (id_u >= 0 && id_v >= 0 && dis[id_u][id_v] < inf)
                ret = min(ret, rec(j + 1) + dis[id_u][id_v]);
        }
        return ret;
    }

public:
    long long minimumCost(string source, string target, vector<string>& from, vector<string>& to, vector<int>& cost) {
        n = source.size();
        s = source, t = target;
        dp = vector<ll>(n, -1);
        tr = Trie();
        
        for (int i = 0; i < from.size(); i++) {
            tr.insert(from[i]);
            tr.insert(to[i]);
        }

        int sz = tr.cur_id;
        dis = vector<vector<ll>>(sz, vector<ll>(sz, inf));
        
        for(int i = 0; i < sz; ++i) dis[i][i] = 0;

        for (int i = 0; i < from.size(); i++) {
            int u = tr.get_id(from[i]);
            int v = tr.get_id(to[i]);
            dis[u][v] = min(dis[u][v], (ll)cost[i]);
        }

        for (int k = 0; k < sz; ++k) {
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz; j++) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        ll ans = rec(0);
        if (ans >= inf) ans = -1;
        return ans;
    }
};