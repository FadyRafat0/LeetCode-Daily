class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ret(2 * n);
        for (int i = 0; i < n * 2; i++) {
            if (i % 2 == 0) ret[i] = nums[i / 2];
            else ret[i] = nums[i / 2 + n];
        }
        return ret;
    }
};