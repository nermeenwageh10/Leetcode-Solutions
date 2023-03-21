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
  bool isLeaf(TreeNode* node){
    return node->left == nullptr && node->right == nullptr;
  }
  bool hasOneChild(TreeNode* node){
    int cnt = (node->left != nullptr) + (node->right != nullptr);
    return cnt == 1;
  }
  TreeNode* getMinNode(TreeNode* node){
    while (node->left != nullptr){
      node = node->left;
    }
    return node;
  }
  TreeNode* deleteNodeHelper(TreeNode* root, int key) {
    if (root == nullptr)
      return root;
    if (root->val < key){
      root->right = deleteNodeHelper(root->right, key);
      return root;
    }
    else if (root->val > key) {
      root->left = deleteNodeHelper(root->left, key);
      return root;
    }
    // children = 0
    if (isLeaf(root)){
      root = nullptr;
      return nullptr;
    }
    // children = 1
    if (hasOneChild(root)){
      return (root->left != nullptr? root->left: root->right);
    }

    
    TreeNode* minNode = getMinNode(root->right);
    root->val = minNode->val;
    root->right = deleteNodeHelper(root->right, minNode->val);
    return root;
  }
  TreeNode* deleteNode(TreeNode* root, int key) {
    root = deleteNodeHelper(root, key);
    return root;
  }
};