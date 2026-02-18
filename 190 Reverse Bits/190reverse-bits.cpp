class Solution {
public:
    int reverseBits(int n) {
        int ret = 0;
        for (int i = 1; i < 31; ++i) {
            int x = (1 << (32 - i - 1));
            if ((x & n))
                ret |= (1 << i);
        }
        return ret;
    }
};