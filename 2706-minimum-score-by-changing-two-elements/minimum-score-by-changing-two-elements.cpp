class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 0 2, 1 1, 2 0
        int n = nums.size();
        int ans = min({nums[n - 3] - nums[0], nums[n - 2] - nums[1], nums[n - 1] - nums[2]});
        return ans;   
    }
};