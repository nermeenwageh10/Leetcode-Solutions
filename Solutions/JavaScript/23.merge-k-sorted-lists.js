/*
 * @lc app=leetcode id=23 lang=javascript
 *
 * [23] Merge k Sorted Lists
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
 * @param {ListNode[]} lists
 * @return {ListNode}
 */

// Solution 2: using MinPriorityQueue
var mergeKLists = function(lists) {
    let result = new ListNode();
    let queue = new MinPriorityQueue({ priority: x => x.val });

    for (let i = 0; i < lists.length; i++) {
        if (lists[i]) {
            queue.enqueue(lists[i]);
        }
    }

    let head = result;

    while (queue.size()) {
        let node = queue.dequeue().element;

        head.next = node;
        head = head.next;

        if (node.next) {
            queue.enqueue(node.next);
        }
    }
    
    return result.next;
};
// @lc code=end


// // Solution 1: Brute Force
// var mergeKLists = function(lists) {
//     let head = new ListNode();
//     let result = head;
//     let min = Infinity;
//     let minIndex = 0;
//     let allEmpty = false;

//     if (!lists.length) {
//         return null;
//     }

//     while (!allEmpty) {
//         min = Infinity;

//         for (let i = 0; i < lists.length; i++) {
//             if (lists[i] && lists[i].val < min) {
//                 min = lists[i].val;
//                 minIndex = i;
//             }
//         }

//         if (min === Infinity) {
//             allEmpty = true;
//         }

//         head.next = lists[minIndex];
//         head = head.next;
//         lists[minIndex] = lists[minIndex] ? lists[minIndex].next : null;
//     }

//     return result.next;
// };

