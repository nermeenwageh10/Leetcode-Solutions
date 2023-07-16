/*
 * @lc app=leetcode id=102 lang=javascript
 *
 * [102] Binary Tree Level Order Traversal
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
 * @return {number[][]}
 */

// Solution 3: DFS
var levelOrder = function(root) {
    var DFS = function(node, level, result) {
        if (!node) return;
        if (result.length === level) result.push([]);
        result[level].push(node.val);
        DFS(node.left, level + 1, result);
        DFS(node.right, level + 1, result);
    }
    let result = [];
    DFS(root, 0, result);
    return result;
};
// @lc code=end


// Solution 2: DFS with FP (just for comparison)
// var currying = function(fn, ...args) {
//     return function(..._args) {
//         return fn.apply(this, args.concat(_args));
//     }
// }

// var trampoline = function(fn) {
//     return function(...args) {
//         let result = fn.apply(this, args);
//         while (typeof result === 'function') {
//             result = result();
//         }
//         return result;
//     }
// }


// var levelOrder = function(root) {
//     const helper = (result, level, node) => {
//         if (!node) return result;
//         const newResult = result.length === level ? [...result, []] : result;
//         const newLevel = level + 1;
//         const leftResult = helper(newResult, newLevel, node.left);
//         const rightResult = helper(leftResult, newLevel, node.right);
//         const currentResult = [...rightResult];
//         currentResult[level].push(node.val);
//         return currentResult;
//     };
    
//     var traverse = trampoline(currying(helper, [], 0));

//     return traverse(root); 
// };


// Solution 1: BFS
// var levelOrder = function(root) {
//     let start = root;
//     let queue = new Queue();
//     let result = [];
//     if (start) {
//         queue.enqueue(start);
//     }
//     while (queue.size() > 0) {
//         let level = [];
//         let size = queue.size();
//         for (let i = 0; i < size; i++) {
//             let node = queue.dequeue();
//             level.push(node.val);
//             if (node.left) queue.enqueue(node.left);
//             if (node.right) queue.enqueue(node.right);
//         }
//         result.push(level);
//     }
//     return result;    
// };


// @after-stub-for-debug-begin
module.exports = levelOrder;
// @after-stub-for-debug-end