class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mn = 1e9;
        for (int i = 0; i < nums.size(); ++i)
            mn = min(mn, (nums[i] == target ? abs(i - start) : (int)1e9));
        return mn;
    }
};