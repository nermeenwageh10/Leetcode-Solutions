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
    void construct(vector<int>& nums, int l, int r, TreeNode*& root){
        if (l > r) return;
        int m = (l+r) >> 1;
        root = new TreeNode(nums[m]);
        construct(nums, l, m - 1, root->left);
        construct(nums, m+1, r, root->right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        construct(nums, 0, nums.size() - 1, root);
        return root;
    }
};