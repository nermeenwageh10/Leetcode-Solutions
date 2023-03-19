class Solution {
public:
    
    int distMoney(int money, int children) {
        if (money < children) return -1;
        int ret = 0;
        for (int i = 1; i <= children; i++){
            int take = i * 8;
            if (take > money) break;
            int rem = money - take;
            int remC = children - i;
            if (rem == 0 && remC == 0){
                ret = i;
                continue;
            }
            if (rem == 0) continue;
            if (remC == 0) continue;
            if (rem >= remC) {
                if (remC == 1 && rem == 4) continue;
                ret = max(ret, i);
            }
        }
        return ret;
    }
};