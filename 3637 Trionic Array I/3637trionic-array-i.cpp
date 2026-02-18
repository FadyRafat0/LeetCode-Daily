class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1, n = nums.size();
        while (i < n && nums[i] > nums[i - 1])
            ++i;
        int p = i - 1;
        while (i < n && nums[i] < nums[i - 1])
            ++i;
        int q = i - 1;
        while (i < n && nums[i] > nums[i - 1])
            ++i;
        return (i == n && 0 < p && p < q && q < n - 1);
    }
};