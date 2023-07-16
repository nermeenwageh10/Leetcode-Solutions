/*
------------------- Hint ----------------------------

We want to find arr the product of all the elements of nums except nums[i].  
Solved by using prefix  Array .   complexity O(N)


  @param {number[]} nums
  @return {number[]}
 */
  var productExceptSelf = function(nums) {
    if (!nums.length) return nums;

    const res = [1];
    for (let i = 0; i < nums.length; i++) {
        const x = res[res.length - 1] * nums[i];
        res.push(x);
    }

    let x = 1;

    for (let i = nums.length - 1; i >= 0; i--) {
        res[i] = x * res[i];
        x = nums[i] * x;
    }
    res.pop(x);
    return res;
};

// another solution:
// without division
// var productExceptSelf = function(nums) {
//   const productBefore = [];
//   const productAfter = [];
//   let product = 1;
//   for (let i = 0; i < nums.length; i++) {
//       productBefore.push(product);
//       product *= nums[i];
//   }
//   product = 1;
//   for (let i = nums.length - 1; i >= 0; i--) {
//       productAfter[i] = product;
//       product *= nums[i];
//   }
//   return nums.map((x, i) => productBefore[i] * productAfter[i]);
// };


// using division
// var productExceptSelf = function(nums) {
//     const countZeros = nums.filter(x => x === 0).length;
//     if (countZeros > 1) return nums.map(x => 0);
//     if (countZeros === 1) return nums.map(x => x === 0 ? product(nums.filter(x => x !== 0)) : 0);
//     const productAll = product(nums);
//     return nums.map(x => productAll / x);
// };