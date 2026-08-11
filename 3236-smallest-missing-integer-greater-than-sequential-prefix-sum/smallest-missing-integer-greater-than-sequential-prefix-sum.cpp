class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) break;
            ans += nums[i];
        }
        set<int> st(nums.begin(), nums.end());
        while (st.find(ans) != st.end()) ++ans;
        return ans;
    }
};