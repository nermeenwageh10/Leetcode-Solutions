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
    vector<int> ret;
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        ret = vector<int>();
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                root = q.front();q.pop();
                if (sz == 0)
                    ret.push_back(root->val);
                if (root->left != nullptr)
                    q.push(root->left);
                if (root->right != nullptr)
                    q.push(root->right);
            }
        }
        return ret;
    }
};