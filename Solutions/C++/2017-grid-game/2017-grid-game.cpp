class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int columns = grid[0].size();
        vector<vector<long long>> prefix(2);
        prefix[0] = vector<long long>(columns, 0);
        prefix[1] = vector<long long>(columns, 0);
        grid[0][0] = grid[1][columns-1] = 0;
        for (int i = 0; i < columns; i++){
            for(int j = 0; j < 2; j++){
                prefix[j][i] = grid[j][i];
                if (i)
                    prefix[j][i] += prefix[j][i-1];
            }
        }
        
        long long mn = 1e18;
        
        for (int i = 0; i < columns; i++){
            long long suffixOfFirstRow = 
                prefix[0][columns-1] - prefix[0][i];
            long long prefixOfSecondRow = (i>0? prefix[1][i-1]: 0);
            mn = min(mn, max(suffixOfFirstRow, prefixOfSecondRow));
        }
        return mn;
        
        
    }
};