class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);
        int mx = 1;
        for (int i = 0; i < nums.size(); i++){ 
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j])
                    LIS[i] = max(LIS[i], LIS[j] + 1);
            }
            mx = max(mx, LIS[i]);
        }
        return mx;
    }
};