class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[i] && s[l] != s[r]) {
                --l, ++r;
                ++ans;
            }
        }
        return ans;
    }
};