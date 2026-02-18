class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> v;
       if (target % 2 == 0)
       {
           if (count(nums.begin(), nums.end(), target / 2) == 2)
           {
               for (int i = 0; i < nums.size(); i++)
               {
                   if (nums[i] == target / 2)
                        v.push_back(i);
               }
               return v;
           }
       }
       map<int, int> mp;
       int j = 1;
       for (int i : nums)
       {
           mp[i] = j;
           j++;
       }
    map<int, int>::iterator first;

    for (first = mp.begin();first != mp.end(); first++)
    {
        if (mp[target - first->first] != 0)
        {
            v.push_back(first->second - 1);
            v.push_back(mp[target - first->first] - 1);
            break;
        }
    }
       return v;
    }
};