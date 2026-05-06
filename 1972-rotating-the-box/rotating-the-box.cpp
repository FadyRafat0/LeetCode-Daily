class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        int n = a.size(), m = a[0].size();
        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[j][n - i - 1] = a[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            for (int i = m - 1, lst = m - 1; i >= 0; --i) {
                if (ans[i][j] == '*') lst = i - 1;
                else if (ans[i][j] == '#') {
                    ans[i][j] = '.';
                    ans[lst][j] = '#';
                    --lst;
                } 
            }
        }

        return ans;
    }
};