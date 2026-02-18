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
public:
    bool ans;
    int dfs(TreeNode *cur) {
        int left = 0, right = 0;
        if (cur->left != nullptr)
            left = dfs(cur->left) + 1;
        if (cur->right != nullptr)
            right = dfs(cur->right) + 1;

        if (abs(left - right) > 1) {
            ans = 0;
        }

        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        ans = 1;
        if (root == nullptr) return ans;
        dfs(root);
        return ans;
    }
};