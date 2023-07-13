/*
 * @lc app=leetcode id=124 lang=javascript
 *
 * [124] Binary Tree Maximum Path Sum
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
 * @param {TreeNode} root
 * @return {number}
 */

var maxPathSum = (root) => {
    let max = -Infinity;
    const dfs = (node) => {
        if (!node) return 0;
        const left = Math.max(0, dfs(node.left));
        const right = Math.max(0, dfs(node.right));
        //Max path in left and right subtrees as you can start from any node
        max = Math.max(max, left + right + node.val);
        return Math.max(left, right) + node.val;
    };
    dfs(root);
    return max;
};
// @lc code=end


