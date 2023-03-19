class Solution {
public:
    vector<int> frq;
    bool can(int cars, long long time){
        for (int i = 1; cars > 0 && i <= 100; i++){
            int tk = 0;
            while (frq[i] - tk > 0){
                tk++;
                // i * x * x <= time 
                // x * x <= time / i
                long long carsHandled = (int)sqrt(time / i);
                if (carsHandled >= cars){
                    cars = 0;break;
                }
                cars -= carsHandled;
            }
        }
        return cars <= 0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        frq = vector<int>(101, 0);
        for (int i = 0; i < ranks.size(); i++) 
            frq[ranks[i]]++;
        long long l = 1, r = 1e14 + 1, m, ans;
        while (l <= r){
            m = (l+r) >> 1LL;
            if (can(cars, m)){
                r = m - 1;
                ans = m;
            }else 
                l = m + 1;
        }
        return ans;
    }
};