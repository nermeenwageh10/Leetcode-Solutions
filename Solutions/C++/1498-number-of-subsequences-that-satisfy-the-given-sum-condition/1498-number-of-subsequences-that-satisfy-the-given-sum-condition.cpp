class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size(), mod = 1e9 + 7;
        vector<int> pow2(n+1, 0);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++)
            pow2[i] = (pow2[i-1] << 1) % mod;
        n--;
        for (int i = 0; i <= n; i++){
            while (i <= n && nums[i] + nums[n] > target)
                n--;
            int len = n - i;
            if (len >= 0)
                ans = (ans + pow2[len] % mod) % mod;
        }
        return ans;
    }
};