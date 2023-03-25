class Solution {
public:
    int minCost[366];
    int minSpend(vector<int>& days, vector<int>& costs, int day){
        if (day > days.back()) return 0;
        int& ret = minCost[day];
        if (~ret) return ret;
        int index = 0;
        while (index < days.size() && days[index] < day)
            index++;
        day = days[index];
        ret = 1e9;
        int period[] = {1, 7, 30};
        for (int i = 0; i < 3; i++){
            ret = min(ret, costs[i] + minSpend(days, costs, day + period[i]));
        }
        return ret;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(minCost, -1, sizeof minCost);
        return minSpend(days, costs, 1);
    }
};