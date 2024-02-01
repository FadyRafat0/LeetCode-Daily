class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& v) {
        int n = v.size();
        vector<long long> pre_sum(n + 1);
        for (int i = 1; i <= n; i++)
            pre_sum[i] = pre_sum[i - 1] + v[i - 1];
        int j = 1;
        long long sum = 0;
        while (j <= n)
        {
            int last = 0;
            for (int i = j; i <= n; i++)
            {
                sum += (pre_sum[i] - pre_sum[last]);
                last++;
            }
            j += 2;
        }

        return sum;
    }
};