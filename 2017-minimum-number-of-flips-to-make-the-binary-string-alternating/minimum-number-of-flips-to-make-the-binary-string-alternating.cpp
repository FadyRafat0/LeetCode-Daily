class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        if (n == 1) {
            return 0;
        }

        s += s;
        vector<int> prf_zero(2 * n + 2), prf_one(2 * n + 2);
    
        for (int i = 1; i <= 2 * n; ++i) {
            if (i >= 2) {
                prf_zero[i] = prf_zero[i - 2];
                prf_one[i] = prf_one[i - 2];
            }

            /* 
              [11111] (en - (i - 2)) + ((en - 1) - (i - 1))
              [1111]  (en - (i - 1)) + ((en - 1) - (i - 2))
            */

            prf_zero[i] += (s[i - 1] != '0');
            prf_one[i] += (s[i - 1] != '1');
        }

        int ans = n;
        for (int i = 1; i <= n; ++i) {
            int en = i + n - 1;
            int op1, op2;

            if (n % 2) {
                op1 = (prf_zero[en] - (i >= 2 ? prf_zero[i - 2] : 0)) + (prf_one[en - 1] - prf_one[i - 1]);
                op2 = (prf_one[en] - (i >= 2 ? prf_one[i - 2] : 0)) + (prf_zero[en - 1] - prf_zero[i - 1]);
            }
            else {
                op1 = (prf_zero[en] - prf_zero[i - 1]) + (prf_one[en - 1] - (i >= 2 ? prf_one[i - 2] : 0));
                op2 = (prf_one[en] - prf_one[i - 1]) + (prf_zero[en - 1] - (i >= 2 ? prf_zero[i - 2] : 0));
            }

            ans = min(ans, min(op1, op2));
        }

        return ans;
    }
};