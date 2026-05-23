class Solution {
public:
    bool check(vector<int>& nums) {
        // 4 5 6 1 2 3 4
        int idx = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (idx != -1) return 0;
                idx = i;
            }
        }
        if (idx == -1) return 1;
        return nums[nums.size() - 1] <= nums[0];
    }
};