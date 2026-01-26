class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int x = i, can = 1;
            while (x) {
                int d = x % 10;
                if (d == 0 || i % d) {
                    can = 0;
                    break;
                }
                x /= 10;
            }
            if (can) ans.push_back(i);
        }
        return ans;
    }
};