class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), len = 0;
        int l = 1, r = n, m;
        while (l <= r){
            m = (l+r) >> 1;
            bool ok = 0;
            int sum = 0;
            for (int i = 0; i < m-1; i++) 
                sum += nums[i];
            for (int i = 0, j = m-1; j < n; i++, j++){
                sum += nums[j];
                if (sum >= target){
                    ok = 1;break;
                }
                sum -= nums[i];
            }
            if (ok){
                len = m;
                r = m - 1;
            }else 
                l = m + 1;
        }
        return len;
    }
};