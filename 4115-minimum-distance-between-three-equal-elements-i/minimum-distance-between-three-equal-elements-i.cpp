class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (nums[i] == nums[j] && nums[i] == nums[k])
                        ans = min(ans, (j - i) + (k - j) + (k - i));
                }
            }
        }
        if (ans == 1e9) ans = -1;
        return ans;
    }
};