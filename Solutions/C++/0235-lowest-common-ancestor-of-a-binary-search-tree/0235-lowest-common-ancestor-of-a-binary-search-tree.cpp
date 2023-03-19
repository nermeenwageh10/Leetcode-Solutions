/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca;
    // 1 found p or q 
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q){
       if (root == nullptr) return 0; 
       int left = dfs(root->left, p, q);
       int right = dfs(root->right, p, q);
       int isRootPOrQ = (root == p || root == q);
       if (left && right && lca == nullptr){
           lca = root;
       }
       
       if ((left || right) && isRootPOrQ){
           if (lca == nullptr)
               lca = root;
       }
       return left || right || isRootPOrQ;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = nullptr;
        dfs(root, p, q);
        return lca;
    }
};