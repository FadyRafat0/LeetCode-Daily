int const static N = 1e5 + 5;
long long dp[N][6][6][3], n, K;
vector<int> v;
class Solution {
public:
    long long rec(int i, int rem, int need, int type) {
        if (i == n) return (rem == need && type);
        long long &ret = dp[i][rem][need][type];
        if (~ret) return ret;
        ret = 0;

        if (type == 0) {
            ret = rec(i + 1, rem, need, type) + rec(i + 1, (rem * v[i]) % K, need, 1);
        }
        else if (type == 1) {
            ret = rec(i + 1, (rem * v[i]) % K, need, type) + rec(i, rem, need, 2);
        }
        else {
            ret = rec(i + 1, rem, need, type);
        }

        return ret;
    }
    vector<long long> resultArray(vector<int>& nums, int k) { 
        v = nums;
        n = v.size();
        K = k;
        for (auto &i : v) i %= k;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (int x = 0; x <= k; ++x) {
                    for (int type = 0; type < 3; ++type) {
                        dp[i][j][x][type] = -1;
                    }
                }
            }
        }
        
        vector<long long> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(rec(0, 1, i, 0));
        }
        return ans;
    }
};