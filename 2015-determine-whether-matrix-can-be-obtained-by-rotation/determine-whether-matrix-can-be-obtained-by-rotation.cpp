class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; ++i) {
            for (int i = 0; i < mat.size(); ++i) {
                for (int j = 0; j < mat[0].size(); ++j) {
                    cout << mat[i][j] << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
            if (mat == target) 
                return true;

            int n = mat.size(), m = mat[0].size();
            vector<vector<int>> tmp;
            for (int j = 0; j < m; ++j) {
                tmp.emplace_back();
                for (int i = n - 1; i >= 0; --i) {
                    tmp.back().emplace_back(mat[i][j]);
                }
            }
            mat = tmp;
        }
        return false;
    }
};