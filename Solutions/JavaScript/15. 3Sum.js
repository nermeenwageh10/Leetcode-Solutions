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