/*
 * @lc app=leetcode id=105 lang=javascript
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */

// inorder: left, root, right
// preorder: root, left, right
// preorder[0] is the root
// find the root in inorder, the left side is left tree, the right side is right tree
// find the left tree in preorder, the right tree in preorder
// recursively build the tree
var buildTree = function(preorder, inorder) {
    
        if(preorder.length === 0 || inorder.length === 0) return null;
    
        let root = new TreeNode(preorder[0]);

        let mid = inorder.indexOf(preorder[0]);

        let leftInorder = inorder.slice(0, mid);
        let rightInorder = inorder.slice(mid + 1);

        let leftPreorder = preorder.slice(1, mid + 1);
        let rightPreorder = preorder.slice(mid + 1);

        root.left = buildTree(leftPreorder, leftInorder);
        root.right = buildTree(rightPreorder, rightInorder);

        return root;
};
// @lc code=end

