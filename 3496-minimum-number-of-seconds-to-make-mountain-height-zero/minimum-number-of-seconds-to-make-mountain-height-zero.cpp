class Solution {
public:
    long long minNumberOfSeconds(int m, vector<int>& a) {
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
        for (int i = 0; i < a.size(); ++i)
            pq.push({a[i], i, 2});

        long long ans = 0;
        while (pq.size() && m--) {
            auto [val, i, cnt] = pq.top();
            pq.pop();
            ans = val;
            pq.push({val + (long long)a[i] * cnt, i, cnt + 1});
        }
        return ans;
    }
};