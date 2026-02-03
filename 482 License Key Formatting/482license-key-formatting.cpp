class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string all;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '-') continue;
            all += s[i];
        }

        reverse(all.begin(), all.end());

        string ans;
        for (int i = 0; i < all.size(); i += k) {
            for (int j = i; j < min((int)all.size(), i + k); ++j) {
                if (all[j] >= 'a' && all[j] <= 'z') {
                    all[j] = toupper(all[j]);
                }
                ans += all[j];
            }
            ans += '-';
        }

        if (ans.size()) {
            ans.pop_back();
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};