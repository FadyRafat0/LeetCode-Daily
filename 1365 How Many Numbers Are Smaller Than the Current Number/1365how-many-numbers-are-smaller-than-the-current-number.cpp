class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> frq(105), prf(105);
        for (auto &i : nums) frq[i]++;
        prf[0] = frq[0];
        for (int i = 1; i < 105; i++) {
            prf[i] = prf[i - 1] + frq[i];
        }
        vector<int> ans(n);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) ans[i] = 0;
            else ans[i] = prf[nums[i] - 1];
        }
        return ans;
    }
};