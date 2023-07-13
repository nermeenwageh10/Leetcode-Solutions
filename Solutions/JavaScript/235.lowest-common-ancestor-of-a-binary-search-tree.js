/*
 * @lc app=leetcode id=235 lang=javascript
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */

// Solution 4: Search in BST
var lowestCommonAncestor = function(root, p, q) {
    if(root.val > p.val && root.val > q.val) return lowestCommonAncestor(root.left, p, q);
    if(root.val < p.val && root.val < q.val) return lowestCommonAncestor(root.right, p, q);
    return root;
};
// @lc code=end


// Solution 3: BFS iterative
// var lowestCommonAncestor = function(root, p, q) {
//     if(!root || root === p || root === q) return root;
//     let parent = new Map();
//     parent.set(root, null);
//     let queue = new Queue();
//     queue.enqueue(root);
//     while(!parent.has(p) || !parent.has(q)) {
//         let node = queue.dequeue();
//         if(node.left) {
//             parent.set(node.left, node);
//             queue.enqueue(node.left);
//         }
//         if(node.right) {
//             parent.set(node.right, node);
//             queue.enqueue(node.right);
//         }
//     }
//     let ancestors = new Set();
//     while(p) {
//         ancestors.add(p);
//         p = parent.get(p);
//     }
//     while(!ancestors.has(q)) {
//         q = parent.get(q);
//     }
//     return q;
// };


// Solution 2: DFS iterative
// var lowestCommonAncestor = function(root, p, q) {
//     if(!root || root === p || root === q) return root;
//     let stack = [root];
//     let parent = new Map();
//     parent.set(root, null);
//     while(!parent.has(p) || !parent.has(q)) {
//         let node = stack.pop();
//         if(node.left) {
//             parent.set(node.left, node);
//             stack.push(node.left);
//         }
//         if(node.right) {
//             parent.set(node.right, node);
//             stack.push(node.right);
//         }
//     }
//     let ancestors = new Set();
//     while(p) {
//         ancestors.add(p);
//         p = parent.get(p);
//     }
//     while(!ancestors.has(q)) {
//         q = parent.get(q);
//     }
//     return q;
// };


// Solution 1: DFS recursive
// var lowestCommonAncestor = function(root, p, q) {
//     if(!root || root === p || root === q) return root;
//     let left = lowestCommonAncestor(root.left, p , q);
//     let right = lowestCommonAncestor(root.right, p , q);
//     if(left && right) return root;
//     return left ? left : right;
// };

