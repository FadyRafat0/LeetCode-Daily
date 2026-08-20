class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a, b;
        a.emplace_back(nums[0]);
        b.emplace_back(nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            if (a.back() > b.back()) a.emplace_back(nums[i]);
            else b.emplace_back(nums[i]);
        }

        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};