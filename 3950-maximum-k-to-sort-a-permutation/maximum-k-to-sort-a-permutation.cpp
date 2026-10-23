class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<bool> vis((int)nums.size());
        int mx = 0;
        while (mx <= nums.size()) mx *= 2, ++mx;

        int ans = mx;
        for (int i = 0; i < nums.size(); ++i) {
            // int j = i, AND = mx;
            // while (!vis[j]) {
            //     vis[j] = 1;
            //     AND &= nums[j];
            //     j = nums[j];
            // }
            if (nums[i] != i)
                ans &= nums[i];
        }
        if (ans == mx) ans = 0;
        return ans;
    }
};