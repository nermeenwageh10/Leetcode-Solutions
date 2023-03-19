/*hint
We want to find top k freq numbers  
Solved by using Array + Hash Table +sort.   complexity O(N+log(m))
*/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
  let mp = new Map();
  for (let i = 0; i < nums.length; i++) {
    mp[nums[i]] = (mp[nums[i]] || 0) + 1;
  }

  let sort_Vector = [];
  for (let i in mp) {
    sort_Vector.push([i, mp[i]]);
  }

  sort_Vector.sort(function (a, b) {
    return b[1] - a[1];
  });

  let res = [];
  for (let i = 0; i < k; i++) {
    res.push(sort_Vector[i][0]);
  }

  return res;
};
