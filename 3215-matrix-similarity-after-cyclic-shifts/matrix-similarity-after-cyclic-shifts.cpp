class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k %= m;
        for (int i = 0; i < n; ++i) {
            vector<int> cur(m);
            for (int j = 0; j < m; ++j) {
                if (i % 2 == 0) cur[j] = mat[i][(j + k) % m];
                else cur[j] = mat[i][(j - k + m) % m];
            }
            if (cur != mat[i])
                return 0;
        }
        return 1;
    }
};