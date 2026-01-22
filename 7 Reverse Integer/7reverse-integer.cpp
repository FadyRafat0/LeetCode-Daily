class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        long long y = abs(1ll * x);
        while (y) {
            ans = (ans * 10 + y % 10);
            y /= 10;
        }
        if (x < 0) ans *= -1;
        
        if (ans < (-1ll << 31) || ans >= (1ll << 31)) 
            ans = 0;
        return ans;
    }
};