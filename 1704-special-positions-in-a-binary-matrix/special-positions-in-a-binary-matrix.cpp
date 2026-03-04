class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> can(n, vector<bool>(m, 1));
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                cnt += mat[i][j];
                can[i][j] = 0;
            }

            if (cnt == 1) {
                for (int j = 0; j < m; ++j) {
                    if (mat[i][j])
                        can[i][j] = 1;
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < m; ++j) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += mat[i][j];   
            }

            if (cnt == 1) {
                for (int i = 0; i < n; ++i) {
                    if (mat[i][j] && can[i][j])
                        ++ans;
                }
            }
        }

        return ans;
    }
};