class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0, n = word.size();
        vector<int> mx_lower(26, -1), mn_upper(26, n);
        for (int i = 0; i < n; ++i) {
            if (islower(word[i])) mx_lower[word[i] - 'a'] = i;
            else if (mn_upper[word[i] - 'A'] == n)
                mn_upper[word[i] - 'A'] = i;
        }

        for (int i = 0; i < 26; ++i) {
            if (mx_lower[i] != -1 && mn_upper[i] != n && mn_upper[i] > mx_lower[i])
                ++ans;
        }

        return ans;
    }
};