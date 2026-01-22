class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> frq(26, 0), have(26, 0);
        for (auto &c : s) frq[c - 'a']++;

        string ans;
        for (auto &c : s) {
            while (!have[c - 'a'] && ans.size() && c < ans.back() && frq[ans.back() - 'a'] > 0) {
                have[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            if (!have[c - 'a']) {
                have[c - 'a'] = 1;
                ans.push_back(c);
            }
            frq[c - 'a']--;
        }
        return ans;
    }
};