/*
------------------- Hint ----------------------------

We want to find any combination of three number.
Solved by using sort  Array && two loop .   complexity O(nlogn) + O(N^2) = O(N^2).

*/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  let res = [];
  let n = nums.length;
  nums = nums.sort((a, b) => a - b);
  for (let i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;

    let x = -nums[i];
    let l = i + 1;
    let r = n - 1;
    while (l < r) {

      if (nums[l] + nums[r] === x) {
        res.push([nums[i], nums[l], nums[r]]);
        while (nums[l] === nums[l + 1]) l++;
        while (nums[r] === nums[r - 1]) r++;
        l++, r--;
      } 

      else if (nums[l] + nums[r] < x) l++;

      else r--;
    }
  }

  return res;
};

//Solution 2: using binary search

// var binarySearchFromIndex = function(nums, target, index) {
//   let left = index;
//   let right = nums.length - 1;
//   let mid = Math.floor((left + right) / 2);
//   while (left <= right) {
//       if (nums[mid] === target) {
//           return mid;
//       } else if (nums[mid] > target) {
//           right = mid - 1;
//           mid = Math.floor((left + right) / 2);
//       } else {
//           left = mid + 1;
//           mid = Math.floor((left + right) / 2);
//       }
//   }
//   return -1;
// }

// var isNotDuplicate = function(result, target) {
//   for (let i = 0; i < result.length; i++) {
//       if (result[i][0] === target[0] && result[i][1] === target[1] && result[i][2] === target[2]) {
//           return false;
//       }
//   }
//   return true;
// }

// var threeSum = function(nums) {
//     const sortedNums = nums.sort((a, b) => a - b);
//     const result = [];
//     for (let i = 0; i < sortedNums.length - 1; i++) {
//         for(let j = i + 1; j < sortedNums.length - 1; j++) {
//             const target = 0 - sortedNums[i] - sortedNums[j];
//             const index = binarySearchFromIndex(sortedNums, target, j + 1);
//             if (index !== -1) {
//                 const targetArray = [sortedNums[i], sortedNums[j], sortedNums[index]];
//                 if (isNotDuplicate(result, targetArray)) {
//                     result.push(targetArray);
//                 }
//             }            
//         }
//     }
//     return result;
// };