class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // a[i] >= min, a[i] -= actual
        // <- a[i]

        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int st = 0, en = 1e9, md, ans = -1;
        while (st <= en) {
            md = (st + en) / 2;
            int cur = md;
            for (auto &p : tasks) {
                if (cur < p[1]) {
                    cur = -1;
                    break;
                }
                cur -= p[0];
            }
            if (cur == -1) st = md + 1;
            else en = md - 1, ans = md;
        }

        return ans;
    }
};