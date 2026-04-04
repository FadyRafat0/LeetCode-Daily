class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        if (s.empty()) return "";
        
        int n = rows, m = s.size() / n;
        string ans;
        for (int j = 0; j < m; ++j) {
            int i = 0, y = j;
            while (i < n && y < m) {
                ans.push_back(s[i * m + y]);
                ++i, ++y;
            }
        }

        while (ans.back() == ' ') ans.pop_back();

        return ans;
    }
};