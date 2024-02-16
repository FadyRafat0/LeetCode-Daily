class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();       
        int k = 0;
        int m = matrix[0].size();

        vector<int> mx(m);
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                mx[j] = max(mx[j], matrix[i][j]);
            }
        }
                            
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = mx[j];
                }
            }
        }      
        return matrix;
    }
};