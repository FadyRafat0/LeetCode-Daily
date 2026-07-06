class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int ans = v.size();
        for (int i = 0; i < v.size(); ++i) {
            int l1 = v[i][0], r1 = v[i][1];
            for (int j = 0; j < v.size(); ++j) {
                if (i == j) continue;
                int l2 = v[j][0], r2 = v[j][1];
                if (l2 <= l1 && r2 >= r1) {
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};