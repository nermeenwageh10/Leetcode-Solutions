class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> temp = nums;
        for (int i = 0; i < n; i++){
            nums[i] = temp[(i + n-k)%n];
        }
    }
};