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
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> ret;
     if (root == nullptr) return ret;
     queue<TreeNode*> q;
     q.push(root);
     while (!q.empty()){
         int sz = q.size();
         vector<int> cur_level;
         while (sz--){
             root = q.front();
             q.pop();
             cur_level.push_back(root->val);
             if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
         }
         ret.push_back(cur_level);
     }
     return ret;   
    }
};