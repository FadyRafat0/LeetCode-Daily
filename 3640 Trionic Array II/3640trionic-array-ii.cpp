class Solution {
private:
    const long long inf = 1e15;
public:
    long long maxSumTrionic(vector<int>& a) {
        int n = a.size();
        vector<int> mx_inc(n), mx_dec(n);
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && a[j] > a[j - 1]) ++j;
            while (i < j) {
                mx_inc[i] = j - 1;
                ++i;
            }
        }
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && a[j] < a[j - 1]) ++j;
            while (i < j) {
                mx_dec[i] = j - 1;
                ++i;
            }
        }

        vector<long long> dp_inc(n + 5, -inf), dp_dec(n + 5, -inf), prf(n + 5);
        for (int i = 0; i < n; i++)
            prf[i] = a[i] + (i ? prf[i - 1] : 0);

        for (int i = n - 1; i >= 0; i--) {
            int idx = mx_inc[i];
            long long sum;
            if (idx != i) {
                // max sum between i and idx
                sum = max(prf[i + 1], prf[idx]) - (i ? prf[i - 1] : 0);
                dp_inc[i] = sum;
            }

            idx = mx_dec[i];
            if (idx != i) {
                sum = prf[idx] - (i ? prf[i - 1] : 0);
                dp_dec[i] = sum + dp_inc[idx] - a[idx];
            }
        }

        long long ans = -inf;
        for (int i = 0; i < n; i++) {
            int idx = mx_inc[i];
            if (idx != i) {
                long long sum = prf[idx] - (i ? prf[i - 1] : 0);
                ans = max(ans, sum + dp_dec[idx] - a[idx]);
            }
        }
        return ans;
    }
};