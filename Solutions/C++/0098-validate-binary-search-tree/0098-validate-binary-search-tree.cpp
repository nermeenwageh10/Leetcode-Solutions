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
    vector<long long> dfs(TreeNode* root)
    {
        long long val = root->val, mn = val, mx = val;
        if (root->left)
        {
            auto left = dfs(root->left);
            if (!left[0] || val <= left[2]) return {0, 0, 0};
            mn = min(mn, left[1]);
        }
        if (root->right)
        {
            auto right = dfs(root->right);
            if (!right[0] || val >= right[1]) return {0, 0, 0};
            mx = max(mx, right[2]);
        }
        return {1, mn, mx};
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return 1;
        auto s = dfs(root);
        return dfs(root)[0];
    }
};