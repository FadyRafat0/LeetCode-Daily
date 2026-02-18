class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int frq[26]{};
            for (int j = i; j < n; j++) {
                frq[s[j] - 'a']++;
                bool same = 1;
                for (auto &f : frq) same &= (f == 0 || f == frq[s[i] - 'a']);
                if (same) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};