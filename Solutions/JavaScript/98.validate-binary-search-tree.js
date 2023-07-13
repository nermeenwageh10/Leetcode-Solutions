/*
 * @lc app=leetcode id=98 lang=javascript
 *
 * [98] Validate Binary Search Tree
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
 * @return {boolean}
 */

// Solution 3: in-order and checking if the array is sorted
var isValidBST = function(root) {

    inOrder = (node) => {
        if (!node)
            return [];
        
        return [...inOrder(node.left), node.val, ...inOrder(node.right)];
    }

    let arr = inOrder(root);

    return arr.every((val, i) => i === 0 || val > arr[i - 1]);    
};

// @lc code=end


// Solution 2: same as solution 1 but with BFS
// var isValidBST = function(root) {
//     if (!root)
//         return true;

//     let queue = new Queue();
//     queue.enqueue({node: root, min: -Infinity, max: Infinity});

//     while (!queue.isEmpty()) {
//         let {node, min, max} = queue.dequeue();
//         if (node.val <= min || node.val >= max)
//             return false;
//         if (node.left)
//             queue.enqueue({node: node.left, min: min, max: node.val});
//         if (node.right)
//             queue.enqueue({node: node.right, min: node.val, max: max});
//     }

//     return true;
// };


// Solution 1: DFS with min and max values for each node
// var isValidBST = function(root) {
//     if (!root)
//         return true;
    
//     function helper (node, min, max) {
//         if (!node)
//             return true;
//         if (node.val <= min || node.val >= max)
//             return false;
//         return helper(node.left, min, node.val) && helper(node.right, node.val, max);
//     }

//     return helper(root, -Infinity, Infinity);
// };


// @after-stub-for-debug-begin
module.exports = isValidBST;
// @after-stub-for-debug-end