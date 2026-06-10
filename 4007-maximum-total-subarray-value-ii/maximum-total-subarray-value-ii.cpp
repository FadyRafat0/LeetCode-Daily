class Solution {
public:
    // 0->based
    struct SparseTable {
        vector<vector<int>> table;
        vector<int> lg;
        int merge(int a, int b) {
            return min(a, b);
        }
        SparseTable(vector<int>& v) {
            int n = v.size();
            lg = vector<int>(n + 5);
            for (int i = 2; i <= n; ++i)
                lg[i] = lg[i / 2] + 1;

            table = vector<vector<int>>(n + 5, vector<int>(lg[n] + 5));
            for (int i = 0; i < n; ++i)
                table[i][0] = v[i];

            for (int sz = 1; sz <= lg[n]; ++sz)
                for (int i = 0; i + (1 << sz) - 1 < n; ++i)
                    table[i][sz] = merge(table[i][sz - 1], table[i + (1 << (sz - 1))][sz - 1]);
        }

        int query(int l, int r) {
            int x = lg[r - l + 1];
            return merge(table[l][x], table[r - (1 << x) + 1][x]);
        }
    };
    vector<int> prvGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> nxtGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()])
                res[st.top()] = i, st.pop();
            st.push(i);
        }
        return res;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        // prv    mx    nxt
        // cur = mx - min[l, r]
        // [l + 1] or [r - 1]

        int n = nums.size();
        SparseTable sp(nums);
        auto prv = prvGreater(nums);
        auto nxt = nxtGreater(nums);

        set<pair<int, int>> vis;
        priority_queue<tuple<int, int, int, int>> pq;
        for (int i = 0; i < n; ++i) {
            int l = prv[i] + 1, r = nxt[i] - 1;
            vis.insert({l, r});
            // cout << l << ' ' << r << '\n';
            pq.push({nums[i] - sp.query(l, r), i, l, r});
        }
        // cout << '\n';

        long long ans = 0;
        while (pq.size() && k--) {
            auto [val, i, l, r] = pq.top();
            pq.pop();
            // cout << val << ' ' << i << ' ' << l << ' ' << r << '\n';
            ans += val;
            if (l + 1 <= i && vis.find({l + 1, r}) == vis.end()) {
                vis.insert({l + 1, r});
                pq.push({nums[i] - sp.query(l + 1, r), i, l + 1, r});
            }
            if (r - 1 >= i && vis.find({l, r - 1}) == vis.end()) {
                vis.insert({l, r - 1});
                pq.push({nums[i] - sp.query(l, r - 1), i, l, r - 1});
            }
        }

        return ans;
    }
};