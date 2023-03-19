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
    void build(vector<int>& pre, vector<int>& in, TreeNode*& root){
        if (in.size() == 0) 
        {
            return;
        }
        root = new TreeNode(pre[0]);
        vector<int> left, right;
        bool rightOn = 0;
        for (int i = 0; i < in.size(); i++){
            if (in[i] == pre[0])
            {
                rightOn = 1;continue;
            }
            if (rightOn)
                right.push_back(in[i]);
            else 
                left.push_back(in[i]);
        }
        pre.erase(pre.begin());
        build(pre, left, root->left);
        build(pre, right, root->right);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       TreeNode* root = nullptr;
       build(preorder, inorder, root);
       return root; 
    }
};