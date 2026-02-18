class Solution {
public:
    int longestBalanced(vector<int>& a) {
        bool vis[(int)1e5 + 5]{};
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            int cur = 0;
            for (int j = i; j < a.size(); j++) {
                if (!vis[a[j]]) {
                    vis[a[j]] = 1;
                    cur += (a[j] % 2 == 0 ? 1 : -1);
                }
                if (cur == 0)
                    ans = max(ans, j - i + 1);
            }
            for (int j = i; j < a.size(); j++) vis[a[j]] = 0;
        }

        return ans;
    }
};