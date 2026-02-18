class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long a = 1, b = 2;
        while (b <= n) {
            if ((bool)(n & a) == (bool)(n & b)) {
                return 0;
            }
            a <<= 1;
            b <<= 1;
        }
        return 1;
    }
};