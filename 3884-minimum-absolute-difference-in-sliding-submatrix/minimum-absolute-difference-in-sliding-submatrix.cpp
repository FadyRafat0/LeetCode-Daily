class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i + k - 1 < n; ++i) {
            ans.emplace_back();
            for (int j = 0; j + k - 1 < m; ++j) {
                
                set<int> st;
                for (int ii = i; ii < i + k; ++ii) {
                    for (int jj = j; jj < j + k; ++jj) {
                        st.insert(grid[ii][jj]);
                    }
                }

                int mn = 1e9;
                for (auto it = st.begin(); next(it) != st.end(); ++it) {
                    mn = min(mn, *next(it) - *it);
                }
                if (mn == 1e9) mn = 0;

                ans.back().emplace_back(mn);
            }
        }

        return ans;
    }
};