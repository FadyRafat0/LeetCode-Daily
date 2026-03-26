class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // if it is 1 row or 1 column then i can just take the ends
        // else with map

        int n = grid.size(), m = grid[0].size();
        long long F_sum = 0, S_sum = 0;
        map<long long, int> F_map, S_map;
        for (auto &i : grid) for (auto &j : i) S_sum += j, S_map[j]++;

        // i want to go from F_sum to S_sum
        auto can = [&](long long dif, int x, int y, int x2, int y2, map<long long, int> &mp) -> int {
            if (dif < 0) return 0;
            if (dif == 0) return 1;

            if (x == x2 || y == y2) {
                return (grid[x][y] == dif || grid[x2][y2] == dif);
            }

            return (mp[dif] > 0);
        };

        for (int i = 0; i < n - 1; ++i) {
            for (auto &j : grid[i])
                F_sum += j, S_sum -= j, S_map[j]--, F_map[j]++;

            if (can(F_sum - S_sum, 0, 0, i, m - 1, F_map)) return 1;
            if (can(S_sum - F_sum, i + 1, 0, n - 1, m - 1, S_map)) return 1;
        }

        F_sum = S_sum = 0;
        F_map.clear(), S_map.clear();
        for (auto &i : grid) for (auto &j : i) S_sum += j, S_map[j]++;

        for (int j = 0; j < m - 1; ++j) {
            for (int i = 0; i < n; ++i) {
                F_sum += grid[i][j];
                S_sum -= grid[i][j];
                S_map[grid[i][j]]--;
                F_map[grid[i][j]]++;
            }

            if (can(F_sum - S_sum, 0, 0, n - 1, j, F_map)) return 1;
            if (can(S_sum - F_sum, 0, j + 1, n - 1, m - 1, S_map)) return 1;
        }

        return 0;
    }
};