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
        
        // 1. Build prefix sums for O(1) score calculation
        memset(pref, 0, sizeof(pref));
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                pref[j][i] = pref[j][i - 1] + grid[i - 1][j - 1];
            }
        }

        // 2. Base case initialization
        memset(dp, 0, sizeof(dp));

        // 3. Bottom-Up DP
        for (int j = m; j >= 1; --j) {
            for (int lst = 0; lst <= n; ++lst) {
                
                // Cheat Sheet 1: Walking down (i <= lst)
                ll best_segment_1 = -1e18;
                for (int i = 0; i <= lst; ++i) {
                    best_segment_1 = max(best_segment_1, dp[j + 1][i][lst] - pref[j][i]);
                }
                // Only Segment 1 actually gets points from the left wall
                best_segment_1 += pref[j][lst]; 

                // Cheat Sheet 2: Hidden upward walk (lst < i <= bef_lst)
                ll pref_max2[105];
                for(int i = 0; i <= n + 1; i++) pref_max2[i] = -1e18;
                for (int i = lst + 1; i <= n; ++i) {
                    pref_max2[i] = max(pref_max2[i - 1], dp[j + 1][i][lst]);
                }

                // Cheat Sheet 3: Breaking new upward ground (i > max(lst, bef_lst))
                ll suff_max3[105];
                for(int i = 0; i <= n + 1; i++) suff_max3[i] = -1e18;
                for (int i = n; i >= 0; --i) {
                    suff_max3[i] = max(suff_max3[i + 1], dp[j + 1][i][lst] + pref[j - 1][i]);
                }

                // Use the Cheat Sheets
                for (int bef_lst = 0; bef_lst <= n; ++bef_lst) {
                    
                    ll ans = best_segment_1;

                    // Segment 2 Check (Notice: No pref[j][lst] added here anymore!)
                    if (bef_lst > lst) {
                        ans = max(ans, pref_max2[bef_lst]);
                    }

                    // Segment 3 Check (Notice: No pref[j][lst] added here anymore!)
                    int threshold = max(lst, bef_lst);
                    if (threshold < n) {
                        ans = max(ans, suff_max3[threshold + 1] - pref[j - 1][threshold]);
                    }

                    dp[j][lst][bef_lst] = ans;
                }
            }
        }

        // 4. Return result starting from column 1
        return dp[1][0][0];
    }
};