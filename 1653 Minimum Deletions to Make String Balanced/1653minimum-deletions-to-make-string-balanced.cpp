class Solution {
public:
    int minimumDeletions(string s) {
        int cnt_a = count(s.begin(), s.end(), 'a');
        int ans = s.size(), cnt_b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') {
                ans = min(ans, cnt_b + cnt_a);
                ++cnt_b;
            }
            else if (s[i] == 'a') {
                --cnt_a;
            }
        }
        ans = min(ans, cnt_b);
        return ans;
    }
};