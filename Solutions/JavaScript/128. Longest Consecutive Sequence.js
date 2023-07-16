/*
------------------- Hint ----------------------------

We want to find arr the product of all the elements of nums except nums[i].  
Solved by using   Array +Hash.   complexity O(N)

*/
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
  let set = new Set(nums);

  let mx = 0;
  for (let i of nums) {

    if (!set.has(i - 1)) {

      let x = 0;
      while (set.has(i)) {
        i++;
        x++;
      }

      mx = Math.max(mx, x);
    }

  }

  return mx;
};

//another solution same above using array instead of set
// var longestConsecutive = function(nums) {
//   const existArray = nums.reduce((acc, x) => {
//       acc[x] = true;
//       return acc;
//   }
//   , {});
//   let max = 0;
//   for (let i = 0; i < nums.length; i++) {
//       if (existArray[nums[i] - 1]) continue;
//       let count = 0;
//       while (existArray[nums[i] + count]) count++;
//       max = Math.max(max, count);
//   }
//   return max;    
// };