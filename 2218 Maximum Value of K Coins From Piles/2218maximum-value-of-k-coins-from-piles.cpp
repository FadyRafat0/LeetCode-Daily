class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        dp[0][k] = 0;
        for (int i = 0; i < n; ++i) {
            int cur = 0;
            for (int j = 0; j <= piles[i].size(); ++j) {
                for (int rem = k; rem - j >= 0; --rem) {
                    dp[i + 1][rem - j] = max(dp[i + 1][rem - j], dp[i][rem] + cur);
                }
                if (j < piles[i].size())
                    cur += piles[i][j];
            }
        }
        return dp[n][0];
    }
};