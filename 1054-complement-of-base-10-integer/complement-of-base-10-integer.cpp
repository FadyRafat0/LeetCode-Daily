class Solution {
public:
    int bitwiseComplement(int n) {

        if (n == 0)
            return 1;
        
        string x;
        while (n) {
            x += (n % 2) + '0';
            n /= 2;
        }

        reverse(x.begin(), x.end());
        
        int ans = 0;
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] == '0')
                ans |= (1 << (x.size() - i - 1));
        }

        return ans;
    }
};