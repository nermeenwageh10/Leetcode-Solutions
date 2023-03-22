/*
if I draw a line from a distance x from the left so the crossed bricks will be the bricks that 
in a row that doesn't have a prfix sum = x
ex:
If you have 2 rows [1, 2, 3, 4]
                   [2, 1, 4, 3]
If I draw a line from a distance 3 from the left, the crossed bricks will be the bricks that doesn't have a prifx sum = 3 which is 0 bricks 
prefixSum of First Row  [1, 3, 6, 10]
prefixSum of Second Row [2, 3, 7, 10]
since each row has a prefix sum = 3, so no bricks is crossed 

so pick x such that prefix = x is maxiumum possible 
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<long long, int> mp;
        for (int i = 0; i < wall.size(); i++){
            long long prefix = 0;
            for (int j = 0; j < wall[i].size() - 1; j++){
                prefix += wall[i][j];   
                mp[prefix]++;
                
            }
        }
        int ans = wall.size();
        for (auto i: mp){
            ans = min(ans, (int)wall.size() - i.second);
        }
        return ans;
    }
};