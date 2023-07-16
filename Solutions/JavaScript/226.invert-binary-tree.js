/*
 * @lc app=leetcode id=226 lang=javascript
 *
 * [226] Invert Binary Tree
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
 * @return {TreeNode}
 */

//

// Solution 3: BFS using queue
var invertTree = function(root) {
    let start = root;
    let queue = new Queue();
    queue.enqueue(start);
    while(queue.size() > 0){
        let node = queue.dequeue();
        if(node){
            [node.left, node.right] = [node.right, node.left];
            queue.enqueue(node.left);
            queue.enqueue(node.right);
        }
    }
    return start;
};

// Solution 2: DFS using recursion
// var invertTree = function(root) {
//     if(!root) return null;
//     [root.left, root.right] = [root.right, root.left];
//     invertTree(root.left);
//     invertTree(root.right);
//     return root;
// };

// Solution 1: DFS using stack
// var invertTree = function(root) {
//     let start = root;
//     let stack = [];
//     stack.push(start);
//     while(stack.length > 0){
//         let node = stack.pop();
//         if(node){
//             [node.left, node.right] = [node.right, node.left];
//             stack.push(node.left);
//             stack.push(node.right);
//         }
//     }
//     return start;  
// };
// @lc code=end

