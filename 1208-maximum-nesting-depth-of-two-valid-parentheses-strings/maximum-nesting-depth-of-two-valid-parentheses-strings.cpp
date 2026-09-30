class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int A = 0, B = 0;
        vector<int> ans;
        for (auto &c : seq) {
            bool cur = 0;
            if (c == '(') {
                if (A <= B) ++A;
                else ++B, cur = 1;
            }
            else {
                if (A >= B) --A;
                else --B, cur = 1;
            }
            ans.emplace_back(cur);
        }
        return ans;
    }
};