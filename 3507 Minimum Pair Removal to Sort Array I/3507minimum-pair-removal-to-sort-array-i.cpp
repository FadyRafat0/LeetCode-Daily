class Solution {
public:
    bool sorted(vector<int> &x) {
        for (int i = 1; i < x.size(); i++) {
            if (x[i] < x[i - 1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (!sorted(nums)) {
            pair<int, int> mn{1e9, 1e9};
            for (int i = 0; i < nums.size() - 1; i++) {
                mn = min(mn, {nums[i] + nums[i + 1], i});
            }
            nums[mn.second] = mn.first;
            nums.erase(nums.begin() + mn.second + 1);
            ++ans;
        }
        
        return ans;
    }
};