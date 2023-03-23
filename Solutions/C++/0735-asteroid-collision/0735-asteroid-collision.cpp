class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        stk.push(asteroids[0]);
        auto collison = [](int a, int b){
            return a > 0 && b < 0;
        };
        for (int i = 1; i < asteroids.size(); i++){
            bool alive = 1;
            while (!stk.empty() && collison(stk.top(), asteroids[i])){
                if (stk.top() < -asteroids[i]){
                    stk.pop();
                }else if (stk.top() > -asteroids[i]){
                    alive = 0;
                    break;
                }else {
                    stk.pop();
                    alive = 0;
                    break;
                }
            }
            if (alive) stk.push(asteroids[i]);
        }
        vector<int> ans((int)stk.size());
        while (!stk.empty()){
            ans[stk.size() - 1] = stk.top();
            stk.pop();
        }
        return ans;
    }
};