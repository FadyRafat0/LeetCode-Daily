class Solution {
public:
    int minAddToMakeValid(string s) {
        int o = 0, ans = 0;
        for (auto &c : s) {
            if (c == ')') {
                if (!o) ++ans;
                else --o;
            }
            else ++o;
        }
        return ans + o;
    }
};