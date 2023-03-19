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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ret;
        if (root == nullptr) return ret;
        bool turn = 0;
        while (!q.empty()){
            int sz = q.size();
            vector<int> level;
            while (sz--){
                root = q.front();
                q.pop();
                level.push_back(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            if (turn)
                reverse(level.begin(), level.end());
            ret.push_back(level);
            turn ^= 1;
        }
        return ret;
    }
};