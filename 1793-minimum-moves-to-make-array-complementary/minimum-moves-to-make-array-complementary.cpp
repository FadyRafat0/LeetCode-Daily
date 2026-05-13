class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        // between 1 and limit

        // i want all of them this sum
        // how many have this sum
        // how many need just 1 modification ->
        // [min, max] will be just 1 modification other wise is 2

        int n = nums.size();
        vector<int> frq(limit * 2 + 2), has_sum(limit * 2 + 2);
        for (int i = 0; i < n - i - 1; ++i) {
            int mn = min(nums[i], nums[n - i - 1]);
            int mx = max(nums[i], nums[n - i - 1]);
        
            frq[mn + 1]++;
            frq[mx + limit + 1]--;
            has_sum[mn + mx]++;
        }

        int ans = 1e9;
        for (int i = 2; i < limit * 2 + 2; ++i) {
            frq[i] += frq[i - 1];
            int cnt_1 = frq[i] - has_sum[i];
            int cnt_2 = n/2 - frq[i];
            ans = min(ans, cnt_1 + cnt_2 * 2);
        }
        return ans;
    }
};