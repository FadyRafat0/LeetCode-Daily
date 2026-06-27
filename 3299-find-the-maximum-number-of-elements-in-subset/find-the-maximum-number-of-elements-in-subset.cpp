class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto &i : nums) mp[i]++;

        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            long long x = nums[i];
            if (x == 1) {
                ans = max(ans, mp[x] - (mp[x] % 2 == 0));
                continue;
            }
            for (int i = 0; i < 35 && x <= 1e9; ++i) {
                if (mp.find(x) == mp.end()) break;
                ans = max(ans, i * 2 + 1);
                if (mp[x] == 1) break;
                x *= x;
            }
        }

        return ans;
    }
};