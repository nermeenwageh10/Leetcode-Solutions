/*hint
We want to check can any value duplicate more than once or not ,there are to solution 
1. using Array + Sorting.      complexity O(NlogN)
2. using Array + Hash Table.   complexity O(N)
So the best solution is Num 2
*/

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {

  const mp = new Map();

  for (let i = 0; i < nums.length; i++) {

    if (mp.get(nums[i])) {
      mp.set(nums[i], mp.get(nums[i]) + 1);
    } else {
      mp.set(nums[i], 1);
    }

    if (mp.get(nums[i]) > 1) return true;
  }
  return false;
};