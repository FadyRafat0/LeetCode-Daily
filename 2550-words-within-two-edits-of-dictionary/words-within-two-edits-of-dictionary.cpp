struct Trie {
    struct Node {
        int vis[26]{};
        int p = 0, en = 0;
    };
    vector<Node> tree;
    Trie() { tree.emplace_back(); }
    void insert(string s) {
        int idx = 0;
        for (auto &i : s) {
            int c = i - 'a';
            if (!tree[idx].vis[c]) {
                tree[idx].vis[c] = tree.size();
                tree.emplace_back();
            }
            idx = tree[idx].vis[c];
            tree[idx].p++;
        }
        tree[idx].en++;
    }
    bool query(int idx, int i, string &s, int cnt) {
        if (cnt > 2) return 0;
        if (i == s.size()) return tree[idx].en;
        bool ret = 0;
        for (int c = 0; c < 26; ++c) {
            int nx = tree[idx].vis[c];
            if (!nx) continue;
            ret |= query(nx, i + 1, s, cnt + (c != (s[i] - 'a')));
        }
        return ret;
    }
};

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        Trie t;
        for (auto &s : dictionary) t.insert(s);

        vector<string> ans;
        for (auto &s : queries) {
            if (t.query(0, 0, s, 0))
                ans.push_back(s);
        }

        return ans;
    }
};