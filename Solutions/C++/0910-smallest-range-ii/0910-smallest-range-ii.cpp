class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) nums[i] += k;
        sort(nums.begin(), nums.end());
        int ans = nums.back() - nums[0];
        priority_queue<vector<int>> pq;
        for (int i = 0; i < nums.size(); i++){
            pq.push({nums[i], (i!=0)});
        }
        int mn = nums[0];
        while (pq.size() > 1 && pq.top()[1]){
            int num1 = pq.top()[0];
            pq.pop();
            int num2 = pq.top()[0];
            int state = pq.top()[1];
            pq.pop();
            ans = min(ans, num1 - mn);
            num1 -= 2 * k;
            mn = min(mn, num1);
            if (num1 >= num2){
                ans = min(ans, num1 - mn);
            }else 
                ans = min(ans, num2 - mn);
           
            pq.push({num1, 0});
            pq.push({num2, state});
        }
        return ans;
    }
};