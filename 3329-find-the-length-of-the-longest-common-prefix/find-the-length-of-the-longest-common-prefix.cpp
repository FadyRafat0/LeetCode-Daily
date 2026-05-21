class Solution {
public:
    struct Node {
        vector<int> nxt;
        Node() {
            nxt.assign(10, 0);
        }
    }; 

    vector<Node> tree;

    void insert(string s) {
        int idx = 0;
        for (auto &i : s) {
            if (tree[idx].nxt[i - '0'] == 0) {
                tree[idx].nxt[i - '0'] = tree.size();
                tree.emplace_back();
            }
            idx = tree[idx].nxt[i - '0'];
        }
    }
    int calc(string s) {
        int ans = 0, idx = 0;
        for (auto &i : s) {
            if (tree[idx].nxt[i - '0'] == 0) break;
            ++ans;
            idx = tree[idx].nxt[i - '0'];
        }
        return ans;
    }
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        tree = vector<Node>(1, Node());
        for (auto &i : arr2) insert(to_string(i));
        int ans = 0;
        for (auto &i : arr1) ans = max(ans, calc(to_string(i)));
        return ans;
    }
};