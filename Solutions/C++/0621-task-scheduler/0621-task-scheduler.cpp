class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26, 0);
        for (int i = 0; i < tasks.size(); i++)
            frq[tasks[i] - 'A']++;
        sort(frq.begin(), frq.end(), [](int a, int b){
            return a > b;
        });
        frq.erase(find(frq.begin(), frq.end(), 0), frq.end());
        vector<int> lst((int)frq.size(), -200);
        int rem = tasks.size();
        int minTime = 0;
        n++;
        int current = 0;
        for (int index = 0; index < rem; index++, current++){
            int take = -1, dist = -1, remm = 0;
            for (int i = 0; i < frq.size(); i++){
                if (frq[i] == 0)continue;
                if (current - lst[i] > dist)                
                {
                    if (dist < n || frq[i] > remm){
                        remm = frq[i];
                        dist = current - lst[i];
                        take = i;
                    }
                }
            }
            minTime++;
            frq[take]--;
            if (dist < n) 
            {
             current += n - dist;
             minTime += n - dist;
            }
            lst[take] = current;
        }
        return minTime;
    }
    
};