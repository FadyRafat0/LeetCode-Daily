class Solution {
public:
    int const mod = 1e9 + 7;
    int mul(long long a, long long b) {
        return (a * b) % mod;
    }
    int fp(long long b, long long e) {
        if (!e) return 1;
        int rs = fp(b, e / 2);
        rs = mul(rs, rs);
        return (e & 1 ? mul(rs, b) : rs);
    }
    int inv(long long b) {
        return fp(b, mod - 2); 
    }
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& que) {
        // k >= SQ then it is okay
        // k < SQ then multiplication of all v such that (i >= l && i <= r)
        // i%k === l%k

        // {l, r, k, v}
        int n = a.size();
        vector<pair<int, int>> ins[n]; // {k, v}
        vector<tuple<int, int, int>> er[n + 1]; // {l, k, v}
        int SQ = sqrt(n);
        for (int i = 0; i < que.size(); ++i) {
            auto l = que[i][0], r = que[i][1], k = que[i][2], v = que[i][3];
            if (k > SQ) {
                while (l <= r) 
                    a[l] = mul(a[l], v), l += k;
            }
            else {
                ins[l].emplace_back(k, v);
                er[r + 1].emplace_back(l, k, v);
            }
        }

        vector<vector<int>> mult(SQ + 5, vector<int>(SQ + 5, 1));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (auto &[k, v] : ins[i]) mult[k][i % k] = mul(mult[k][i % k], v);
            for (auto &[l, k, v] : er[i]) mult[k][l % k] = mul(mult[k][l % k], inv(v));

            for (int x = 1; x <= SQ; ++x)
                a[i] = mul(a[i], mult[x][i % x]);
        
            ans ^= a[i];
        }

        return ans;
    }
};