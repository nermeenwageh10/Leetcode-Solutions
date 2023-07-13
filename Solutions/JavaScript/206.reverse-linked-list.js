/*
 * @lc app=leetcode id=206 lang=javascript
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function (head) {
  let currentNode = head;
  let prevNode = null;
  while (currentNode) {
    [currentNode.next, prevNode, currentNode] = [prevNode, currentNode, currentNode.next];
  }
  return prevNode;
};

// for readability purpose:
// function reverseLinkedList(head) {
//     let currentNode = head;
//     let prevNode = null;
//     while (currentNode) {
//       const nextNode = currentNode.next;
//       currentNode.next = prevNode;
//       prevNode = currentNode;
//       currentNode = nextNode;
//     }
//     return prevNode;
//   }

// @lc code=end
