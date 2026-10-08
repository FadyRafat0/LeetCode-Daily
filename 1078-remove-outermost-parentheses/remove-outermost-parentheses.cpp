class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int o = 0;
        for (auto &c : s) {
            if (c == '(') {
                if (o) ans += c;
                ++o;
            }
            else {
                if (o != 1) ans += c;
                --o;
            }
        }   
        return ans;
    }
};