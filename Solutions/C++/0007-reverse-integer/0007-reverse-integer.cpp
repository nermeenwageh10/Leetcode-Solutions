class Solution {
public:
    int reverse(int x) {
        long long  ans = 0;
        int si = (x < 0? -1: 1); 
        x = abs(x); 
        while (x)
        {
            ans = ans * 10 + x % 10;
            x/=10;
        }
        ans *= si;
        if (ans > (1LL<<31)-1 || ans < -1*((1LL<<31)))
            return  0 ;
        return ans ;
    }
};