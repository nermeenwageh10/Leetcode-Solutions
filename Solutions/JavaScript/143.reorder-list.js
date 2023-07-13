/*
 * @lc app=leetcode id=143 lang=javascript
 *
 * [143] Reorder List
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
 * @return {void} Do not return anything, modify head in-place instead.
 */



// Solution 2: O(n) time, O(1) space
var reorderList = function (head) {
    let middle = findMiddle(head);
    let secondHalf = reverseList(middle.next);
    middle.next = null;
    mergeLists(head, secondHalf);
};



// Solution 1: O(n) time, O(n) space
// var reorderList = function (head) {
//   let currentNode = head;
//   let map = new Map();
//   let count = 0;

//   while (currentNode) {
//     map.set(count, currentNode);
//     currentNode = currentNode.next;
//     count++;
//   }

//   let i = 0;
//   let j = count - 1;

//   while (i < j) {
//     map.get(i).next = map.get(j);
//     i++;
//     if (i === j) {
//       break;
//     }
//     map.get(j).next = map.get(i);
//     j--;
//   }
//   map.get(i).next = null;
// };

var findMiddle = function (head) {
    let slow = head;
    let fast = head;

    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }

    return slow;
};

var reverseList = function (head) {
    let prev = null;
    let current = head;

    while (current) {
        [current.next, prev, current] = [prev, current, current.next];
    }

    return prev;
};

var mergeLists = function (head1, head2) {
    let head = new ListNode();
    let currentNode = head;

    while (head1 && head2) {
        currentNode.next = head1;
        head1 = head1.next;
        currentNode = currentNode.next;
        currentNode.next = head2;
        head2 = head2.next;
        currentNode = currentNode.next;
    }

    currentNode.next = head1 || head2;
    
    return head.next;
};

// @lc code=end
