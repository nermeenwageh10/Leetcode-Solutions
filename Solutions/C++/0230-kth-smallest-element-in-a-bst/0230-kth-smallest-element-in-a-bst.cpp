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
    int get_size(TreeNode* root){
        if (root == nullptr) return 0;
        return 1 + get_size(root->left) + get_size(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (k == 0) return root->val;
        int sz = (root? get_size(root->left): 0) + 1;
        if (sz > k) return kthSmallest(root->left, k);
        if (sz == k)return root->val;
        return kthSmallest(root->right, k - sz);
    }
};