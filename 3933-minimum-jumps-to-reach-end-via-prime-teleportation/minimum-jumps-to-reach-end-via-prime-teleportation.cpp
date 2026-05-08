const int N = 1e6 + 5;
int spf[N];
bool is_precomputed = false;

void pre() {
    for (int i = 2; i < N; ++i) spf[i] = i;
    for (int i = 2; i < N; ++i) {
        if (spf[i] == i) {
            for (long long j = 1ll * i * i; j < N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
    is_precomputed = true;
}

class Solution {
public:
    int minJumps(vector<int>& nums) {
        if (!is_precomputed) {
            pre();
        }
        unordered_map<int, vector<int>> go;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                go[p].push_back(i);
                while (x % p == 0) x /= p;
            }
        }

        vector<int> dis(n, 1e9);
        queue<int> q;
        dis[0] = 0;
        q.push(0);

        while (q.size()) {
            auto u = q.front();
            q.pop();

            if (u > 0 && dis[u - 1] == 1e9) {
                dis[u - 1] = dis[u] + 1;
                q.push(u - 1);
            }
            if (u + 1 < n && dis[u + 1] == 1e9) {
                dis[u + 1] = dis[u] + 1;
                q.push(u + 1);
            }

            if (spf[nums[u]] == nums[u]) {
                for (auto &v : go[nums[u]]) {
                    if (dis[v] == 1e9) {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                }
                go[nums[u]].clear();
            }
        }

        return dis[n - 1];
    }
};