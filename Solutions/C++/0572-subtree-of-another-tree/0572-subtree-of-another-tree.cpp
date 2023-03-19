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
    bool check(TreeNode* tree1, TreeNode* tree2){
        if (tree1 == nullptr && tree2 == nullptr) return 1;
        if (tree1 == nullptr || tree2 == nullptr) return 0;
        if (tree1->val != tree2->val) return 0;
        return (check(tree1->left, tree2->left) &&
                check(tree1->right, tree2->right));  
    }
    bool dfs(TreeNode* root, TreeNode* sub){
        if (root == nullptr && sub == nullptr) return 1;
        if (root == nullptr || sub == nullptr) return 0;
        if (root->val == sub->val){
            if (check(root, sub))
                return 1;
        }
        return dfs(root->left, sub) || 
               dfs(root->right, sub);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};