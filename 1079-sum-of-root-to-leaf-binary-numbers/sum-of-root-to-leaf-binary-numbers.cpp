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
    int dfs(TreeNode *u, int msk) {
        if (u == nullptr) return 0;
        if (u->val)
            msk |= 1;
        if (u->left == nullptr && u->right == nullptr) {
            return msk;   
        }
        return dfs(u->left, msk * 2) + dfs(u->right, msk * 2);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};