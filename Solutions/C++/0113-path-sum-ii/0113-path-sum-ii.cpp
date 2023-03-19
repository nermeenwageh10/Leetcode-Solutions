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
    vector<int> curPath;
    vector<vector<int>> paths;
    bool isLeaf(TreeNode* root)
    {
        return (root->left == nullptr && root->right == nullptr);
    }
    void dfs(TreeNode* root, int target, int curSum = 0)
    {
        if (root == nullptr) return;
        curPath.push_back(root->val);
        curSum += root->val;
        if (isLeaf(root))
        {
            if (target == curSum)
                paths.push_back(curPath);
            curPath.pop_back();
            return;
        }
        dfs(root->left, target, curSum);
        dfs(root->right, target, curSum);
        curPath.pop_back();
        curSum -= root->val;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        curPath.clear();
        paths.clear();
        dfs(root, targetSum);
        return paths;
    }
};