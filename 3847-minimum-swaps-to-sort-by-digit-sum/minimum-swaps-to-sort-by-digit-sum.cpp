class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = (int)nums.size();
        vector<tuple<int, int, int>> srt;
        for (int i = 0; i < n; ++i) {
            int sum = 0, x = nums[i];
            while (x) sum += x % 10, x /= 10;
            srt.emplace_back(sum, nums[i], i);
        }
        sort(srt.begin(), srt.end());
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            auto [a,b,c] = srt[i];
            pos[i] = c;
        }
        int ans = 0;
        vector<bool> vis(n);
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            int sz = 0, j = i;
            while (!vis[j]) {
                vis[j] = 1;
                ++sz;
                j = pos[j];
            }
            ans += sz - 1;
        }
        return ans;
   }
};