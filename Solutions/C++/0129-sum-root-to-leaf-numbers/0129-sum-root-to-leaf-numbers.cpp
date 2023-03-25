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
    int sum(TreeNode* root, int val)
    {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr)
            return val * 10 + root->val;
        int cur = (root->val);
        return sum(root->left, val * 10 + cur) + sum(root->right, val * 10 + cur); 
    }
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
};