class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> frq(n + 2, 0);
        for (auto &x : nums) {
            frq[x]++;
        }

        int missing = -1, twice = -1; 
        for (int i = 1; i <= n; i++) {
            if (frq[i] == 2) twice = i;
            if (frq[i] == 0) missing = i;
        }
        return {twice, missing};
    }
};