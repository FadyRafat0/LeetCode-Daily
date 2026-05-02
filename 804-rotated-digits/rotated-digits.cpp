class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i, can = 0;
            while (x) {
                int d = x % 10;
                if (d == 3 || d == 4 || d == 7) {
                    can = 0;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9)
                    can = 1;
                x /= 10;
            }
            ans += can;
        }
        return ans;
    }
};