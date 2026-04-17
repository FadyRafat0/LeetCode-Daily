class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> mp;
        int ans = 1e9;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i]) != mp.end())
                ans = min(ans, i - mp[nums[i]]);

            string s = to_string(nums[i]);
            int x = 0;
            for (int j = s.size() - 1; j >= 0; --j) {
                x = (x * 10 + s[j] - '0');
            }
            mp[x] = i;
        }

        return (ans == 1e9 ? -1 : ans);
    }
};