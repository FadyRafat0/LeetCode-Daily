class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j)
            {
                if (v[j] > v[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int mx = 0;
        for (auto &i : dp)
            mx = max(mx, i);
        return mx;
    }
};