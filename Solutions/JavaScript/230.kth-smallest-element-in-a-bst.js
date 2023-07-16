/*
 * @lc app=leetcode id=230 lang=javascript
 *
 * [230] Kth Smallest Element in a BST
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
 * @param {number} k
 * @return {number}
 */

// Solution 3: Priority Queue
const kthSmallest = (root, k) => {
    const queue = new MinPriorityQueue({ priority: x => x.val });
    let count = 0;
    
    var enqueue = (node) => {
        if (node.left) enqueue(node.left);
        queue.enqueue(node);
        if (node.right) enqueue(node.right);
    }

    enqueue(root);

    while(k > 0) {
        result = queue.dequeue();
        k--;
    }

    return result.element.val;
};
// @lc code=end


// Solution 2: turn BST into sorted array
// var kthSmallest = function(root, k) {

//     inOrder = (node) => {
//         if (!node)
//             return [];

//         return [...inOrder(node.left), node.val, ...inOrder(node.right)];
//     }

//     let arr = inOrder(root);

//     return arr[k - 1];
// };

// Solution 1: In-order traversal
// var kthSmallest = function(root, k) {
//     let result = [];
//     let traverse = (node) => {
//         if (node.left) traverse(node.left);
//         result.push(node.val);
//         if (node.right) traverse(node.right);
//     }
//     traverse(root);
//     return result[k-1];    
// };

