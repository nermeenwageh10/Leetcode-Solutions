class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int N = 100001;
        vector<int> frq(N, 0);
        long long curMass = mass;
        for (int i = 0; i < asteroids.size(); i++)
            frq[asteroids[i]]++;
        for (int i = 1; i < N && curMass < N-1; i++){
            if (frq[i] == 0) continue;
            if (i > curMass) return 0;
            curMass += 1LL * frq[i] * i;
        }
        return 1;
    }
};