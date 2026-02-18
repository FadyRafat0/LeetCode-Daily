/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> order;
public:
    void dfs(TreeNode *cur) {
        if (cur == nullptr) return;
        order.push_back(cur->val);
        dfs(cur->left);
        dfs(cur->right);
    }
    TreeNode* rec(int st, int en) {
        if (st > en) return nullptr;
        int md = (st + en) / 2;

        TreeNode *left = rec(st, md - 1);
        TreeNode *right = rec(md + 1, en);

        return new TreeNode(order[md], left, right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        sort(order.begin(), order.end());
        return rec(0, order.size() - 1);
    }
};