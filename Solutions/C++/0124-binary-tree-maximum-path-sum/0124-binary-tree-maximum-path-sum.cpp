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
    vector<int> dfs(TreeNode* root)
    {
        // left, right, Max
        if (root == nullptr) return {0, 0, (int)-1e9};
        int lsum = root->val;
        int rsum = root->val;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        lsum = max(lsum, lsum + max(left[0], left[1]));
        rsum = max(rsum, rsum + max(right[0], right[1]));
        return {lsum, rsum, 
                max({left[2], 
                     right[2], 
                     root->val, 
                     root->val + max({0, left[0], left[1]}) 
                         + max({0, right[0], right[1]})
                     })};
    }
    int maxPathSum(TreeNode* root) {
        auto mx = dfs(root);
        int Max = mx[0];
        if (Max < mx[1]) Max = mx[1];
        if (Max < mx[2]) Max = mx[2];
        return Max;
    }
};