class Solution {
public:

    string addBinary(string a, string b) {
        string ans;

        int rem = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int A = 0, B = 0;
            if (i >= 0) A = a[i] - '0';
            if (j >= 0) B = b[j] - '0';
            ans += ((A + B + rem) % 2) + '0';
            rem += (A + B);
            if (rem >= 2) rem = 1;
            else rem = 0;
        }
        if (rem) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};