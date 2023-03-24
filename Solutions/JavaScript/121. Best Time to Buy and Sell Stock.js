/*
------------------- Hint ----------------------------

We want to  find min and max number from the array
Solved by using  	Two Pointers .   complexity  O(N).

*/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let l = 0, r = 1, mx = 0;

  while (r < prices.length) {

    if (prices[l] < prices[r]) {
      mx = Math.max(mx, prices[r] - prices[l]);
    } else {
      l = r;
    }
    r++;

  }
  return mx;
};