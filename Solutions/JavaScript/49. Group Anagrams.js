/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  const mp = new Map();
  let res = [];

  for (let i = 0; i < strs.length; i++) {
    let x = strs[i].split("").sort().join("");
    if (mp.has(x)) {
      mp.get(x).push(strs[i]);
    } else mp.set(x, [strs[i]]);
  }

  mp.forEach((val)=>{
    res.push(val)
  })

  return res;
};