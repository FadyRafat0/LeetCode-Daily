class Solution {
    #define all(v) v.begin(), v.end()
public:
    int minOperations(vector<int>& v) {
        int n = v.size();
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        int ans = n;
        for (int i = 0; i < v.size(); ++i)
        {
            int st = i, en = v.size() - 1, md;
            int mx = i;
            while (st <= en)
            {
                md = (st+ en) / 2;
                if (v[md] <= v[i] + (n-1))
                    st = md + 1, mx = md;
                else
                    en = md - 1;
            }
            ans = min(ans, (int)n - (mx - i + 1));
        }
        return ans;
    }
};