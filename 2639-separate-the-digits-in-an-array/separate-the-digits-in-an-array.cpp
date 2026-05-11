class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto &x : nums) {
            for (auto c : to_string(x)) ans.emplace_back(c - '0');
        }
        return ans;
    }
};