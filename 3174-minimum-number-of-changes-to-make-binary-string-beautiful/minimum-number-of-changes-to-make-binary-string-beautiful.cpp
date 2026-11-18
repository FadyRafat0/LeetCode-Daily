class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                ans += (i%2);
            }
        }
        return ans;
    }
};