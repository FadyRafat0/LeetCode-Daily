class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        // i want first row to be x 0 0 0 0 0
        // second row             x x 0 0 0 0

        // (n - 1) 0's
        // (n - 2) 0's
        int n = grid.size();
        int cnt = n - 1;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int zeros = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j]) break;
                ++zeros;
            }
            a[i] = zeros;
        }

        int ans = 0;
        for (int i = 0, cnt = n - 1; i < n; ++i, --cnt) {
            int idx = -1;
            for (int j = i; j < n; ++j) {
                if (a[j] >= cnt) {
                    idx = j;
                    break;
                }
            }

            if (idx == -1)  
                return -1;

            ans += idx - i;
            int prv = a[idx];
            a.erase(a.begin() + idx);
            a.insert(a.begin() + i, a[idx]);
        }

        return ans;
    }
};