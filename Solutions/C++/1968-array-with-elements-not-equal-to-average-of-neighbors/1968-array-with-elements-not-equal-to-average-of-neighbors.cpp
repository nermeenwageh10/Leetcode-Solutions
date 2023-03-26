class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i + 1 < n; i++){
            if (nums[i-1] + nums[i+1] == 2 * nums[i]){
                swap(nums[i], nums[i+1]);
            }
        }
        for (int i = n-2; i > 0; i--){
            if (nums[i-1] + nums[i+1] == 2 * nums[i]){
                swap(nums[i], nums[i+1]);
            }
        }
        return nums;
    }
};