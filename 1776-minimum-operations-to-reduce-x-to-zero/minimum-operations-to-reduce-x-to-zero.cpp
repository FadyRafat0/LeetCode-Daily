class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int cur = 0, ans = n + 1;

        while (cur < x && r >= 0) cur += nums[r--];

        ++r;

        if (cur == x)
            ans = n-r;

        for (int l = 0; l < n; ++l) {
            if (l != r) cur += nums[l];
            else ++r;

            while (cur > x && r < n) cur -= nums[r], ++r;

            if (cur == x)
                ans = min(ans, (l + 1) + (n - r));
        }

        return ans == n + 1 ? -1 : ans;
    }
};