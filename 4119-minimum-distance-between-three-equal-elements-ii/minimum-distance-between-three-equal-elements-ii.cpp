class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) mp[nums[i]].push_back(i);
        int ans = 1e9;
        for (auto &[x, v] : mp) {
            for (int i = 0; i + 2 < v.size(); ++i) {
                ans = min(ans, (v[i + 1] - v[i]) + (v[i + 2] - v[i + 1]) + (v[i + 2] - v[i]));
            }
        }
        if (ans == 1e9) ans = -1;
        return ans;
    }
};