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

// Solution 2: Brute Force
// var isAnagram = function(s, t) {
//   if (s.length !== t.length) {
//       return false;
//   }
  
//   let freq = new Array(26).fill(0);
//   for (let i = 0; i < s.length; i++) {
//       freq[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
//       freq[t.charCodeAt(i) - 'a'.charCodeAt(0)]--;
//   }
  
//   for (let i = 0; i < freq.length; i++) {
//       if (freq[i] !== 0) {
//           return false;
//       }
//   }
  
//   return true;
// };
// var groupAnagrams = function(strs) {
//   let arr = [];
//   let done = {};
//   for(let i = 0; i < strs.length; i++){
//       let temp = [];
//       if (!done[strs[i]]){
//           for(let j=0;j<strs.length;j++){
//               if(isAnagram(strs[i],strs[j])){
//                   temp.push(strs[j]);
//                   done[strs[j]] = true;
//               }
//           }
//       }
//       if(temp.length)
//       arr.push(temp);
//   }
//   return arr;
// };