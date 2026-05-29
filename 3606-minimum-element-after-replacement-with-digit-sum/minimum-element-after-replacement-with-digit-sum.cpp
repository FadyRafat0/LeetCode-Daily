class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 1e9;
        for (auto &i : nums) {
            int x = 0;
            while (i) {
                x += i % 10;
                i /= 10;
            }
            ans = min(ans, x);
        }
        return ans;
    }
};