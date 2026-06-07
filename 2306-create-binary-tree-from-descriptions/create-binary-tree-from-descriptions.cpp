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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int const N = 1e5 + 2;
        vector<int> in(N), vis(N);
        vector<TreeNode*> ans(N, NULL);
        for (auto &v : descriptions) {
            int p = v[0], child = v[1], left = v[2];
            in[child]++;
            
            if (ans[p] == NULL) ans[p] = new TreeNode(p);
            if (ans[child] == NULL) ans[child] = new TreeNode(child);
            
            if (left) ans[p]->left = ans[child];
            else ans[p]->right = ans[child];
            vis[p] = vis[child] = 1;
        }
        
        TreeNode* root = NULL;
        for (int i = 1; i < N; ++i) {
            if (vis[i] && !in[i])
                root = ans[i];
        }

        return root;
    }
};