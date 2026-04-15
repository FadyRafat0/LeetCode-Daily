class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = 1e9;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] != target) continue;
            ans = min(ans, abs(i - startIndex));
            ans = min(ans, (int)words.size() - max(i, startIndex) + min(i, startIndex));
        }        
        return (ans == 1e9 ? -1 : ans);
    }
};