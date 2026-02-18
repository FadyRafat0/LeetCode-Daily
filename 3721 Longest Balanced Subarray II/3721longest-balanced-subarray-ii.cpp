struct Node {
    int mn = 0, mx = 0;
};
// 0->Based
struct lazySegTree {
    vector<Node> tree;
    vector<int> lazy;
    Node skip;
    int sz;
    lazySegTree(int n){
        sz = n;
        int m = 1;
        while (m <= n) m *= 2;
        tree.resize(m * 2);
        lazy.resize(m * 2);
        skip = {(int)1e9, (int)-1e9};
    }
    Node single(int val) {
        Node ret;   
        ret.mn = ret.mx = val;
        return ret;
    }
    Node merge(Node l, Node r) {
        Node ret;
        ret.mn = min(l.mn, r.mn);
        ret.mx = max(l.mx, r.mx);
        return ret;
    }
    void prop(int node, int l, int r) {
        if (!lazy[node]) return;
        tree[node].mn += lazy[node];
        tree[node].mx += lazy[node];
        if (l != r) {
            lazy[node * 2] += lazy[node];     // edit
            lazy[node * 2 + 1] += lazy[node]; // edit
        }
        lazy[node] = 0;
    }
    void update_range(int node, int l, int r, int st, int en, int val) {
        prop(node, l, r);
        if (l > en || r < st) return;
        if (l >= st && r <= en) {
            lazy[node] += val; // edit
            prop(node, l, r);
            return;
        }
        int md = (l + r) / 2;
        update_range(node * 2, l, md, st, en, val);
        update_range(node * 2 + 1, md + 1, r, st, en, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    void update_range(int st, int en, int val) {
        update_range(1, 0, sz - 1, st, en, val);
    }
    int query(int node, int l, int r) {
        prop(node, l, r);
        if (l == r) return l;
        int md = (l + r) / 2;
        prop(node * 2 + 1, md + 1, r);
        if (tree[node * 2 + 1].mx >= 0 && tree[node * 2 + 1].mn <= 0)
            return query(node * 2 + 1, md + 1, r);
        return query(node * 2, l, md);
    }
    int query() {
        return query(1, 0, sz - 1);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        lazySegTree seg(n);
        vector<int> srt;
        for (auto &i : nums) srt.push_back(i);
        sort(srt.begin(), srt.end());
        srt.erase(unique(srt.begin(), srt.end()), srt.end());

        vector<deque<int>> v(srt.size());
        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            idx[i] = lower_bound(srt.begin(), srt.end(), nums[i]) - srt.begin();
            if (v[idx[i]].empty()) {
                seg.update_range(i, n - 1, (nums[i] % 2 ? 1 : -1));
            }
            v[idx[i]].push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, seg.query() - i + 1);

            seg.update_range(i, n - 1, (nums[i] % 2 ? -1 : 1));
            v[idx[i]].pop_front();
        
            if (v[idx[i]].size()) {
                seg.update_range(v[idx[i]][0], n - 1, (nums[i] % 2 ? 1 : -1));
            }
        }
        if (ans == 1) ans = 0;
        return ans;
    }
};