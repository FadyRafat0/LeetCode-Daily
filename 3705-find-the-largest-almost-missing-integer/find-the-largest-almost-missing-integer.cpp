class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // exactly one subarray of size k
        // the first one and the last one

        if (k == nums.size())
            return *max_element(nums.begin(), nums.end());

        if (k == 1) {
            int ans = -1;
            map<int, int> mp;
            for (auto &i : nums) mp[i]++;
            for (auto &[a,c] : mp) {
                if (c == 1) ans = a;
            }
            return ans;
        }
    
        int cnt_1 = count(nums.begin(), nums.end(), nums.front());
        int cnt_n = count(nums.begin(), nums.end(), nums.back());

        int ans = -1;
        if (cnt_1 == 1) ans = nums.front();
        if (cnt_n == 1) ans = max(ans, nums.back());
        return ans;
    }
};