class Solution {
public:
    bool can(vector<int>& nums, int len, int k)
    {
      long long sum = 0;
      for (int i = 0; i < len - 1; i++)
      {
        sum += nums[i]; 
      }
      for (int i = 0, j = len-1; j < nums.size(); j++, i++)
      {
        sum += nums[j]; 
        long long need = 1LL * nums[j] * len; 
        if (need - sum <= k)return 1; 
        sum -= nums[i];
      }
      return 0;
    }
    int maxFrequency(vector<int>& nums, int k) {
      int l = 1, r = nums.size(), m, ans = 0;
      sort(nums.begin(), nums.end());
      while(l <= r)
      {
        m = (l+r) >> 1;
        if(can(nums, m, k))
          ans = m, l = m+1; 
        else 
          r = m-1;
      }
      return ans;
    }
};