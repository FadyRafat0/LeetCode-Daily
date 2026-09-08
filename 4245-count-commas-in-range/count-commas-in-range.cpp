class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i, cnt = 0;
            while (x) ++cnt, x /= 10;
            ans += (cnt - 1) / 3;
        }
        return ans;
    }
};