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
    bool check(TreeNode* l, TreeNode* r){
        if (l == nullptr && r == nullptr) return 1;
        if (l == nullptr || r == nullptr) return 0;
        if (l->val != r->val) return 0;
        return check(l->left, r->right) && check(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return 1;
        return check(root->left, root->right);
    }
};