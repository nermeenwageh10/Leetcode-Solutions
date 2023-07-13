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