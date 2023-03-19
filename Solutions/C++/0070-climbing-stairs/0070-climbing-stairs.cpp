class Solution {
public:
    int climbStairs(int n) {
       if (n <= 2)  return n;
       int prv = 2, prvPrv = 1, cur;
       n-=2;
       while(n--){
        cur = prv + prvPrv;
        prvPrv = prv;
        prv = cur;
       } 
       return cur;
    }
};