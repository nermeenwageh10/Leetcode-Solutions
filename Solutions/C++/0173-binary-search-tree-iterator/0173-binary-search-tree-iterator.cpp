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
class BSTIterator {
public:
    stack<TreeNode*> stk;
    void add(TreeNode* root){
        while (root){
            stk.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        add(root);
    }
    
    int next() {
        auto node = stk.top();
        stk.pop();
        add(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return stk.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */