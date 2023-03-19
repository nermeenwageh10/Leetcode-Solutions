class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0, j = 31; i < j; i++, j--){
            if (!!(n & (1LL<<i)) == !!(n & (1LL<<j))) continue;
            n ^= (1LL<<i);
            n ^= (1LL<<j);
        }
        return n;
    }
};