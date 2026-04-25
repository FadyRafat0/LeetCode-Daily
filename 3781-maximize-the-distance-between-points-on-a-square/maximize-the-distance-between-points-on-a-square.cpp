class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        // sort clock wise order then
        // (x=0,y), (x,y=side), (x=side,-y),(-x,y=0)
        vector<long long> arr;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                arr.push_back(y);
            } else if (y == side) {
                arr.push_back(side + x);
            } else if (x == side) {
                arr.push_back(side * 3LL - y);
            } else {
                arr.push_back(side * 4LL - x);
            }
        }

        sort(arr.begin(), arr.end());

        auto check = [&](int md) {
            for (long long start : arr) {
                long long end = start + side * 4LL - md;
                long long cur = start;
                for (int i = 0; i < k - 1; i++) {
                    auto it = lower_bound(arr.begin(), arr.end(), cur + md);
                    if (it == arr.end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }
                if (cur >= 0)
                    return true;
            }
            return false;
        };

        int st = 1, en = side, md, ans = -1;
        while (st <= en) {
            md = (st + en) / 2;
            if (check(md)) {
                st = md + 1;
                ans = md;
            }
            else {
                en = md - 1;
            }
        }

        return ans;
    }
};