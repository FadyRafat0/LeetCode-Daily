#define ll long long

class Solution {
public:
    // dp[column][lst][bef_lst]
    ll dp[105][105][105];
    ll pref[105][105];
    int n, m;

    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        memset(pref, 0, sizeof(pref));
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                pref[j][i] = pref[j][i - 1] + grid[i - 1][j - 1];
            }
        }

        memset(dp, 0, sizeof(dp));
        for (int j = m; j >= 1; --j) {
            for (int lst = 0; lst <= n; ++lst) {
                
                ll best_segment_1 = -1e18;
                for (int i = 0; i <= lst; ++i) {
                    best_segment_1 = max(best_segment_1, dp[j + 1][i][lst] - pref[j][i]);
                }
                best_segment_1 += pref[j][lst]; 

                ll pref_max2[105];
                for(int i = 0; i <= n + 1; i++) pref_max2[i] = -1e18;
                for (int i = lst + 1; i <= n; ++i) {
                    pref_max2[i] = max(pref_max2[i - 1], dp[j + 1][i][lst]);
                }

                ll suff_max3[105];
                for(int i = 0; i <= n + 1; i++) suff_max3[i] = -1e18;
                for (int i = n; i >= 0; --i) {
                    suff_max3[i] = max(suff_max3[i + 1], dp[j + 1][i][lst] + pref[j - 1][i]);
                }

                for (int bef_lst = 0; bef_lst <= n; ++bef_lst) {
                    
                    ll ans = best_segment_1;

                    if (bef_lst > lst) {
                        ans = max(ans, pref_max2[bef_lst]);
                    }

                    int threshold = max(lst, bef_lst);
                    if (threshold < n) {
                        ans = max(ans, suff_max3[threshold + 1] - pref[j - 1][threshold]);
                    }

                    dp[j][lst][bef_lst] = ans;
                }
            }
        }

        return dp[1][0][0];
    }
};