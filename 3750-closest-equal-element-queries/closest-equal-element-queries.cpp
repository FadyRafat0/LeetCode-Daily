class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) mp[nums[i]].push_back(i);

        int n = nums.size();
        auto get = [&](int i, int j) {
            return min(abs(i - j), n - max(i, j) + min(i, j));
        };

        for (int i = 0; i < queries.size(); ++i) {
            int idx = queries[i];
            int ans = -1;
            int val = nums[idx];
            auto &vec = mp[val];
            if (vec.size() > 1) {
                ans = 1e9;
                auto it = lower_bound(vec.begin(), vec.end(), idx);

                if (next(it) != vec.end()) ans = min(ans, get(idx, *next(it)));
                if (it != vec.begin()) ans = min(ans, get(idx, *prev(it)));

                if (vec[0] != idx)
                    ans = min(ans, get(idx, vec[0]));
                if (vec.back() != idx)
                    ans = min(ans, get(idx, vec.back()));
            }

            queries[i] = ans;
        }

        return queries;
    }
};