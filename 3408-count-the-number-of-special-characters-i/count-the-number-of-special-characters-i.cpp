class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            bool lower = find(word.begin(), word.end(), 'a' + i) != word.end();
            bool upper = find(word.begin(), word.end(), 'A' + i) != word.end();
            ans += (lower && upper);
        }
        return ans;
    }
};