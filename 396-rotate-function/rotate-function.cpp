class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            a.push_back(a[i]);
        int cur_ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            cur_ans += a[i] * i;
            sum += a[i];
        }

        int ans = cur_ans;
        for (int i = n; i < 2 * n; ++i) {
            sum -= a[i - n];
            cur_ans -= sum;
            sum += a[i];
            cur_ans += a[i] * (n - 1);

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};