class Solution {
    vector<pair<int, int>> v;
    vector<vector<int>> dp;
    vector<int> w;

    int rec(int i, bool prv_R) {
        if (i == v.size()) return 0;
        int &ret = dp[i][prv_R];
        if (~ret) return ret;
        ret = 0;
        int L = (i == 0 ? 0 : v[i - 1].first) + 1;
        if (prv_R) L += v[i - 1].second;

        // take L
        int cnt = 0;
        L = max(L, v[i].first - v[i].second);

        int R = v[i].first;
        if (L <= R) {
            cnt = upper_bound(w.begin(), w.end(), R) - lower_bound(w.begin(), w.end(), L);
        }
        ret = max(ret, rec(i + 1, 0) + cnt);

        // take R
        L = v[i].first;
        R = (i == v.size() - 1 ? 1e9 : v[i + 1].first - 1);
        R = min(R, v[i].first + v[i].second);

        cnt = upper_bound(w.begin(), w.end(), R) - lower_bound(w.begin(), w.end(), L);

        ret = max(ret, rec(i + 1, 1) + cnt);

        return ret;
    }
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        for (int i = 0; i < robots.size(); ++i) {
            v.emplace_back(robots[i], distance[i]);
        }

        sort(v.begin(), v.end());
        w = walls;
        sort(w.begin(), w.end());

        int n = v.size();
        dp = vector<vector<int>>(n, vector<int>(2, -1));
    
        return rec(0, 0);
    }
};