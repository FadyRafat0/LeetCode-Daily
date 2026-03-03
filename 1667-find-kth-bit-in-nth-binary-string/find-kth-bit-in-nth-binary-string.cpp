class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 1; i <= n; ++i) {
            string nw_s = s + "1";
            reverse(s.begin(), s.end());
            for (auto &c : s) c = (c - '0') ^ 1 + '0';
            nw_s += s;
            s = nw_s;
        }
        return s[k - 1];
    }
};