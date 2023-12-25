class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int index;
        int mid = (low + high) / 2;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                break;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (nums[mid] >= target)
            index = mid;
        else
            index = mid + 1;

        return index;
    }
};