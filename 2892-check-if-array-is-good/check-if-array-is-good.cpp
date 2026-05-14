class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> frq(nums.size());
        for (auto &i : nums) {
            if (i >= frq.size()) return 0;
            frq[i]++;
            if (i < nums.size() - 1) {
                if (frq[i] > 1) return 0;
            }
            else {
                if (frq[i] > 2) return 0;
            }
        }

        return 1;
    }
};