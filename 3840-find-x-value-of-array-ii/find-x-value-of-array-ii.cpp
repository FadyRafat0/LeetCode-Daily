struct Node {
    int mul = 1;
    array<int, 5> prf{};
};
struct SegmentTree {
    vector<Node> tree;
    int n, k;
    Node skip;
    SegmentTree(int n, int k): n(n), k(k) {
        int m = 1;
        while (m <= n) m *= 2;
        tree.resize(m * 2);
    }
    Node single(int val) {
        Node ret;
        ret.mul = val;
        ret.prf[val] = 1;
        return ret;
    }
    Node merge(Node L, Node R) {
        Node ret;
        ret.mul = (L.mul * R.mul) % k;
        for (int x = 0; x < k; ++x) {
            ret.prf[x] += L.prf[x];
            ret.prf[(x * L.mul) % k] += R.prf[x];
        }
        return ret;
    }
    void build(int node, int l, int r, vector<int> &a) {
        if (l == r) {
            tree[node] = single(a[l]);
            return;
        }
        int md = (l + r) / 2;
        build(node * 2, l, md, a);
        build(node * 2 + 1, md + 1, r, a);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = single(val);
            return;
        }
        int md = (l + r) / 2;
        if (idx <= md) update(node * 2, l, md, idx, val);
        else update(node * 2 + 1, md + 1, r, idx, val);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    Node query(int node, int l, int r, int st) {
        if (r < st) return skip;
        if (l >= st) return tree[node];
        int md = (l + r) / 2;
        return merge(query(node * 2, l, md, st), query(node * 2 + 1, md + 1, r, st)); 
    }
    Node query(int st) {
        return query(1, 0, n - 1, st);
    }
};
class Solution {
public:


    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // segment tree
        // number of ways to reach each X
        // the left one i cannot remove any one
        // the right one i can remove any suffix right? so i can take any prefix from it!
        // 

        // vector<int> ans(5), prf(5);
        // int mul

        /*
            single
            prf[x] = 1
            mul = x


            in merge
            so i can take the answer from the left one
            prf = L.ans
            i can take any one from the right
            prf[i] += prf[(i * L.mul) % k];

            mul = L.mul * R.mul
        */

        for (auto &x : nums) x %= k;

        int n = nums.size();
        SegmentTree seg(n, k);
        seg.build(1, 0, n - 1, nums);

        // 0,10

        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int idx = queries[i][0], val = queries[i][1], st = queries[i][2], x1 = queries[i][3];            
            seg.update(idx, val % k);
            auto cur = seg.query(st);
            ans.emplace_back(cur.prf[x1]);
        }

        return ans;
    }
};