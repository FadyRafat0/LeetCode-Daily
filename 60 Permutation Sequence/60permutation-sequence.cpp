class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n + 1, 1); 
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i;

        string ans;
        vector<bool> vis(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (vis[j]) continue;
                if (k <= fac[n - i]) {
                    ans += (j + '0');
                    vis[j] = 1;
                    break;
                }
                k -= fac[n - i];
            }
        }
        return ans;
    }
};