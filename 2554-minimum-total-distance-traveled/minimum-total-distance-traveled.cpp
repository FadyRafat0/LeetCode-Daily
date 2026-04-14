class Solution {
public:
    int static const N = 105;
    long long dp[N][N];
    vector<int> a;
    vector<vector<int>> b;
    long long rec(int i, int j) {
        if (j == b.size() || i == a.size()) return (i == a.size() ? 0 : 1e18);
        long long &ret = dp[i][j];
        if (~ret) return ret;
        ret = rec(i, j + 1);
        long long sum = 0;
        for (int take = i; take < a.size() && take - i < b[j][1]; ++take) {
            sum += abs(a[take] - b[j][0]);
            ret = min(ret, rec(take + 1, j + 1) + sum);
        }
        return ret;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // dp[i][j][k]
        a = robot, b = factory;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        memset(dp, -1, sizeof dp);
        return rec(0, 0);
    }
};