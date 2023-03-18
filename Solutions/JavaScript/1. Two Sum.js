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