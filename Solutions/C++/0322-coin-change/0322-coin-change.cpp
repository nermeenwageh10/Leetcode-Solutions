class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int inf = 1e9;
        vector<int> minCoins(amount+1, inf);
        minCoins[0] = 0;
        for (int curAmount = 1; curAmount <= amount; curAmount++){
            for (int& coin: coins){
                if (coin > curAmount) continue;
                minCoins[curAmount] = min(minCoins[curAmount], 
                            1 + minCoins[curAmount-coin]);
            }
        }
        if (minCoins[amount] == inf) 
            return -1;
        return minCoins[amount];
    }
};