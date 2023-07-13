/*hint
We want to find sum of any two numbers equal a target number and print index of them 
Solved by using Array + Hash Table.   complexity O(N)
*/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const mp = new Map();
  let res=[];

  for (let i = 0; i < nums.length; i++) {

    if (mp.get(target - nums[i])!== undefined && mp.get(target - nums[i]) !== i) {
      res.push(i);
      res.push(mp.get(target - nums[i]))
    }
    mp.set(nums[i], i);
  }
  return res;
};

// Solution 2: Sorting + Two pointers
// var twoSum = function(nums, target) {
//   let left = 0;
//   let right = nums.length - 1;
//   let sorted = [...nums].sort((a, b) => a - b);
//   while (left < right) {
//       let sum = sorted[left] + sorted[right];
//       if (sum === target) {
//           return [nums.indexOf(sorted[left]), nums.lastIndexOf(sorted[right])];
//       }
//       if (sum < target) {
//           left++;
//       } else {
//           right--;
//       }
//   }
// };