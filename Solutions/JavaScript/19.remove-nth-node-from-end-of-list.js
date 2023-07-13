/*
 * @lc app=leetcode id=19 lang=javascript
 *
 * [19] Remove Nth Node From End of List
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
 * @param {number} n
 * @return {ListNode}
 */

// Solution 3: in one pass using two pointers
var removeNthFromEnd = function (head, n) {
    let fastPointer = head;
    let slowPointer = head;

    for (let i = 0; i < n; i++) {
        fastPointer = fastPointer.next;
    }

    if (!fastPointer) {
        return head.next;
    }

    while (fastPointer.next) {
        fastPointer = fastPointer.next;
        slowPointer = slowPointer.next;
    }

    slowPointer.next = slowPointer.next.next;

    return head;
};


// Solution 2: using a pointer
// var removeNthFromEnd = function (head, n) {
//     let currentNode = head;
//     let count = 0;
//     while (currentNode) {
//         count++;
//         currentNode = currentNode.next;
//     }
//     let index = count - n;
    
//     currentNode = head;

//     while (index > 1) {
//         currentNode = currentNode.next;
//         index--;
//     }

//     if (index === 0) {
//         return currentNode.next;
//     }

//     currentNode.next = currentNode.next.next;

//     return head;
// };

// Solution 1: using array
// var removeNthFromEnd = function(head, n) {
//     let array = [];
//     let currentNode = head;
//     while (currentNode) {
//         array.push(currentNode);
//         currentNode = currentNode.next;
//     }
//     let index = array.length - n;
//     if (index === 0) {
//         return array[1] || null;
//     }
//     array[index - 1].next = array[index + 1] || null;
//     return head;
// };
// @lc code=end

