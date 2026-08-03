class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frq(26);
        for (auto &c : word) frq[c - 'a']++;

        sort(frq.rbegin(), frq.rend());
        int ans = 0, cur = 0;
        for (int i = 0; i < 26; ++i) {
            if (i % 8 == 0) ++cur;
            ans += cur * frq[i];
        }
        return ans;
    }
};