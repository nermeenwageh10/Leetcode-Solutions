class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            // if I can start from station [i], 
            // gas needed should be less than or equal to the gas the station provide
            if (gas[i] < cost[i]) continue;
            int tank = gas[i] - cost[i];
            int j = (i + 1) % n;
            bool faild = 0;
            // check If I can travel around the circuit once 
            while (j != i)
            {
                tank += gas[j];
                if (tank < cost[j])
                {
                    faild = 1;break;
                }
                tank -= cost[j];
                j = (j + 1) % n;
            }
            if (faild)
            {
                if (j < i) 
                    break;
                i = j - 1;
                continue;
            }
            return i;
        }
        return -1;
    }
};