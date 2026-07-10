class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> srt;
        for (int i = 0; i < n; ++i) {
            srt.emplace_back(nums[i], i);
        }

        sort(srt.begin(), srt.end());

        vector<int> id(n);
        vector<vector<int>> jump(n, vector<int>(18, -1));
        for (int i = n - 1, j = n - 1; i >= 0; --i) {
            auto [val, u] = srt[i];
            while (srt[j].first - val > maxDiff) --j;
            
            id[u] = i;
            jump[i][0] = j;

            for (int k = 1; k < 18; ++k) {
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
            }
        }

        vector<bool> ans;
        for (auto &que : queries) {
            int u = que[0], v = que[1];
            int id_u = id[u], id_v = id[v];
            if (id_u > id_v) swap(id_u, id_v);

            int cost = 0;
            for (int k = 17; k >= 0; --k) {
                if (jump[id_u][k] >= id_v) continue;
                assert(jump[id_u][k] != -1);
                cost += (1 << k);
                id_u = jump[id_u][k];
            }

            if (id_u != id_v) {
                if (jump[id_u][0] >= id_v)
                    ++cost;
                else
                    cost = -1;
            } 

            ans.emplace_back(cost >= 0);
        }

        return ans;
    }
};