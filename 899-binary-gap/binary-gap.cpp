class Solution {
public:
    int binaryGap(int n) {
        vector<int> v;
        for (int i = 0; i < 30; ++i) {
            if ((1 << i) & n)
                v.push_back(i);
        }
        int ans = 0;
        for (int i = 1; i < v.size(); ++i)
            ans = max(ans, v[i] - v[i - 1]);

        return ans;
    }
};