class Solution {
public:
    // 9,30,16,6,36,9
    vector<int> maxValue(vector<int> nums) {
        int n = nums.size();
        vector<int> suf(n);
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = nums[i];
            if (i + 1 < n)
                suf[i] = min(suf[i], suf[i + 1]);
        }

        vector<int> prf(n);
        for (int i = 0; i < n; ++i) {
            prf[i] = nums[i];
            if (i) prf[i] = max(prf[i], prf[i - 1]);
        }

        vector<int> ans(n);
        ans[n - 1] = prf[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (prf[i] > suf[i + 1]) ans[i] = ans[i + 1];
            else ans[i] = prf[i];
        }
        return ans;
    }
};