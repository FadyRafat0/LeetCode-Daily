class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int, int>> go;
        int sum = 0;
        for (int i = 0; i < s.size();) {
            int j = i;
            while (j < s.size() && s[i] == s[j]) ++j;
            sum += (s[i] == '1' ? j - i : 0);
            go.emplace_back(s[i] - '0', j - i);
            i = j;
        }

        int mx = 0;
        for (int i = 1; i + 1 < go.size(); ++i) {
            if (go[i].first == 1) {
                mx = max(mx, go[i - 1].second + go[i + 1].second);
            }
        }
        return sum + mx;
    }
};