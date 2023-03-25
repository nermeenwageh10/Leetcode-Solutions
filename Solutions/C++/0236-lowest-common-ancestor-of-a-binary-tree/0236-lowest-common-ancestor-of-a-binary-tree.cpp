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
    unordered_map<int, int> compress;
    vector<int> height;
    vector<TreeNode*> par;
    void doCompress(TreeNode* root)
    {
        if (root == nullptr) return;
        // assert all values are unique 
        int id = compress.size();
        compress[root->val] = id;
        doCompress(root->left);
        doCompress(root->right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        compress.clear();
        par.clear();
        height.clear();
        doCompress(root);
        height = vector<int>((int)compress.size());
        par = vector<TreeNode*>((int)compress.size());
        queue<TreeNode*> bfs;
        bfs.push(root);
        par[compress[root->val]] = nullptr;
        height[compress[root->val]] = 0;
        while(!bfs.empty())
        {
            auto cur = bfs.front();
            bfs.pop();
            if (cur->left != nullptr)
            {
                par[compress[cur->left->val]] = cur;
                height[compress[cur->left->val]] = height[compress[cur->val]] + 1;
                bfs.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                par[compress[cur->right->val]] = cur;
                height[compress[cur->right->val]] = height[compress[cur->val]] + 1;
                bfs.push(cur->right);
            }
        }
        while(p != q)
        {
            if (height[compress[p->val]] < height[compress[q->val]])
            {
                q = par[compress[q->val]];
            }else 
            {
                p = par[compress[p->val]];
            }
        }
        return p;
        
    }
};