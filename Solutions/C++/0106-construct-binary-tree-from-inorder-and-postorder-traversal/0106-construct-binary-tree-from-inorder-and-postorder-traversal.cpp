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
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder, int inLeft, 
    int inRight, int& postIndex){
        if (inLeft > inRight) return nullptr;
        postIndex--;
        if (inLeft == inRight){
            return new TreeNode(inOrder[inLeft]);
        }
        TreeNode* root = new TreeNode(postOrder[postIndex]);
        int rootIndex = -1;
        for (int i = inLeft; i <= inRight; i++){
            if (inOrder[i] == postOrder[postIndex]){
                rootIndex = i;
                break;
            }
        }
        root->right = buildTree(inOrder, postOrder, rootIndex + 1, inRight, postIndex);
        root->left = buildTree(inOrder, postOrder, inLeft, rootIndex - 1, postIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size();
        return buildTree(inorder, postorder, 0, inorder.size()-1, postIndex);
    }
};