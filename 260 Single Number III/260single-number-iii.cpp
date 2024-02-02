class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       map<int, int> mp;
       for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        vector<int> ans;
        for (auto i : mp)
        {
            if (i.second == 1)
                ans.push_back(i.first);
            if (ans.size() == 2)
                break;
        }
        return ans;
    }
};