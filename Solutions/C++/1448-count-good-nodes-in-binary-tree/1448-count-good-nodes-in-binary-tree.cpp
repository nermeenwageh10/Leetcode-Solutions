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
    int goodNodesHelper(TreeNode* root, int pathMax){
        if (root == nullptr) return 0;
        int val = root->val;
        return (val >= pathMax) + goodNodesHelper(root->left, max(pathMax, val))+
            goodNodesHelper(root->right, max(pathMax, val));
    }
    int goodNodes(TreeNode* root) {
        return goodNodesHelper(root, -1e9);
    }
};