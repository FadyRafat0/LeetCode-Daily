class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (int i = 0; i < words.size(); ++i) {
            int cur = 0;
            for (auto &c : words[i]) cur += weights[c - 'a'];
            cur %= 26;
            cur = (25 - cur);
            ans += (cur + 'a');
        }
        return ans;
    }
};