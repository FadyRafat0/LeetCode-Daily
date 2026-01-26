class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // n % k == 0
        vector<bool> vis(k + 5, 0);
        int cur = 1 % k, steps = 1;
        while (!vis[cur] && cur > 0) {
            ++steps;
            vis[cur] = 1;
            cur = (cur * 10) + 1;
            cur %= k;
        }
        return (cur == 0 ? steps : -1);
    }
};