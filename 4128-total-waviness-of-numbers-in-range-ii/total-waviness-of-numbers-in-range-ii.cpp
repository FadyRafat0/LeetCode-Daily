class Solution {
public:
    struct ST {
        long long sum = -1, ways = 0;
    };
    // N, up, down, lst_prv, prv, cur
    ST dp[18][2][2][10][10][3];
    string l, r;
    bool valid(int a, int b, int c) {
        return (b > a && b > c) || (b < a && b < c);
    }
    ST rec(int i, bool up, bool down, int lst_prv, int prv, int cnt) {
        if (i == r.size()) return {0, 1};
        ST &ret = dp[i][up][down][lst_prv][prv][cnt];
        if (~ret.sum) return ret;
        ret.sum = ret.ways = 0;

        int st = (down ? l[i] - '0' : 0);
        int en = (up ? r[i] - '0' : 9);
        for (int d = st; d <= en; ++d) {
            int nw_cnt = (cnt == 0 ? (d != 0) : cnt + 1);
            nw_cnt = min(nw_cnt, 2);

            auto nxt = rec(i + 1, (up && d == en), (down && d == st), prv, d, nw_cnt);
            ret.sum += nxt.sum;
            ret.ways += nxt.ways;
            if (cnt == 2 && valid(lst_prv, prv, d))
                ret.sum += nxt.ways;
        }
        return ret;
    } 
    long long totalWaviness(long long num1, long long num2) {
        memset(dp, -1, sizeof dp);
        l = to_string(num1);
        r = to_string(num2);
        while (l.size() < r.size()) l = "0" + l;
        return rec(0, 1, 1, 0, 0, 0).sum;
    }
};