struct Trie {
    struct Node {
        int vis[26]{};
        int len = 1e9, idx = -1;
    };
    vector<Node> tree;
    Trie() { tree.emplace_back(); }
    void insert(int i, string s) {
        int idx = 0;
        if (tree[idx].len > s.size())
                tree[idx].len = s.size(), tree[idx].idx = i;
        for (auto &ch : s) {
            int c = ch - 'a';
            if (!tree[idx].vis[c]) {
                tree[idx].vis[c] = tree.size();
                tree.emplace_back();
            }
            idx = tree[idx].vis[c];
            if (tree[idx].len > s.size())
                tree[idx].len = s.size(), tree[idx].idx = i;
        }
    }
    int query(string s) {
        int idx = 0;
        for (auto &i : s) {
            int c = i - 'a';
            if (!tree[idx].vis[c]) return tree[idx].idx;
            idx = tree[idx].vis[c];
        }
        return tree[idx].idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie t;
        for (int i = 0; i < wordsContainer.size(); ++i) {
            auto s = wordsContainer[i];
            reverse(s.begin(), s.end());
            t.insert(i, s);
        }
        vector<int> ans;
        for (auto &s : wordsQuery) {
            reverse(s.begin(), s.end());
            ans.emplace_back(t.query(s));
        }
        return ans;
    }
};