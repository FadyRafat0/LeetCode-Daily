class Solution {
public:
    int maxDistance(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] != a[j])
                    ans = max(ans, j - i);
            }
        }
        return ans;
    }
};