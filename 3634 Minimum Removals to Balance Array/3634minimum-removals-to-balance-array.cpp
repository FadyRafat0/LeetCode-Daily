class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            int it = upper_bound(nums.begin(), nums.end(), 1ll * nums[i] * k) - nums.begin();
            ans = min(ans, i + (n - it));
        }
        return ans;
    }
};