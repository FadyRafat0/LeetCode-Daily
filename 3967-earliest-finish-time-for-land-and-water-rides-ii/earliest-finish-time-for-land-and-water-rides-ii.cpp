class Solution {
public:
    int earliestFinishTime(vector<int>& start_a, vector<int>& d_a, vector<int>& start_b, vector<int>& d_b) {
        int n = start_a.size(), m = start_b.size();
        vector<pair<int, int>> a(n), b(m);

        for (int i = 0; i < n; ++i) a[i] = {start_a[i], d_a[i]};
        for (int i = 0; i < m; ++i) b[i] = {start_b[i], d_b[i]};

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> prf_a(n, 1e9), suf_a(n + 1, 1e9), prf_b(m, 1e9), suf_b(m + 1, 1e9);
        for (int i = 0; i < n; ++i) {
            prf_a[i] = min((i == 0 ? (int)1e9 : prf_a[i - 1]), a[i].second);
        }
        for (int i = n - 1; i >= 0; --i) {
            suf_a[i] = min(suf_a[i + 1], a[i].first + a[i].second);
        }
        for (int i = 0; i < m; ++i) {
            prf_b[i] = min((i == 0 ? (int)1e9 : prf_b[i - 1]), b[i].second);
        }
        for (int i = m - 1; i >= 0; --i) {
            suf_b[i] = min(suf_b[i + 1], b[i].first + b[i].second);
        }

        int mn = 1e9;
        for (int i = 0; i < n; ++i) {
            int finish = a[i].first + a[i].second;
            auto it = lower_bound(b.begin(), b.end(), pair<int, int>{finish, -1}) - b.begin();
            int cur = suf_b[it];
            if (it > 0) cur = min(cur, finish + prf_b[it - 1]);

            mn = min(mn, cur);
        }

        for (int i = 0; i < m; ++i) {
            int finish = b[i].first + b[i].second;
            auto it = lower_bound(a.begin(), a.end(), pair<int, int>{finish, -1}) - a.begin();
            int cur = suf_a[it];
            if (it > 0) cur = min(cur, finish + prf_a[it - 1]);

            mn = min(mn, cur);
        }

        return mn;
    }
};