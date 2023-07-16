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

// Solution 2: Frequency Array + sort
// var topKFrequent = function(nums, k) {
//   const frequency = {};
//   for (let i = 0; i < nums.length; i++) {
//       frequency[nums[i]] = frequency[nums[i]] ? frequency[nums[i]] + 1 : 1;
//   }
//   const frequencyArray = Object.keys(frequency).map(key => ({ key, value: frequency[key] }));
//   frequencyArray.sort((a, b) => b.value - a.value);
//   return frequencyArray.slice(0, k).map(item => item.key);
// };

/*
this is a one line solution, but it is not efficient as the above solution
var topKFrequent = function(nums, k) {
  return Object.entries(nums.reduce((acc, cur) => {
      acc[cur] = acc[cur] ? acc[cur] + 1 : 1;
      return acc;
  }
  , {})).sort((a, b) => b[1] - a[1]).slice(0, k).map(item => item[0]);
};*/