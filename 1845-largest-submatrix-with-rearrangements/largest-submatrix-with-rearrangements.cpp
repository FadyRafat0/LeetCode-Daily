class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        // n * n * m

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prf(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!mat[i][j]) continue;
                prf[i][j] = 1 + (i ? prf[i - 1][j] : 0);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            sort(prf[i].begin(), prf[i].end(), greater<>());

            for (int j = 0; j < m; ++j) {
                ans = max(ans, (j + 1) * prf[i][j]);
            }
        }

        return ans;
    }
};