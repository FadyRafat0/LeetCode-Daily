class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1e9);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] - nums[i] >= -target && nums[j] - nums[i] <= target)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return (dp[0] < 0 ? -1 : dp[0]);
    }
};