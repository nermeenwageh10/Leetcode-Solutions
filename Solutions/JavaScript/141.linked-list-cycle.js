/*
 * @lc app=leetcode id=141 lang=javascript
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {boolean}
 */

// Solution 2: Floyd's Tortoise and Hare
var hasCycle = function(head) {
    let slowPointer = head;
    let fastPointer = head;
    while (fastPointer && fastPointer.next) {
        slowPointer = slowPointer.next;
        fastPointer = fastPointer.next.next;
        if (fastPointer === slowPointer) return true;
    }
    return false;
};

// Solution 1: visited set
// var hasCycle = function(head) {
//     let current = head;
//     let set = new Set();
//     while (current) {
//         if (set.has(current)) return true;
//         set.add(current);
//         current = current.next;
//     }
//     return false;
// };
// @lc code=end

