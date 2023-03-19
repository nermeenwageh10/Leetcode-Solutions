class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int answer, mx, mn;
      answer = mx = mn = nums[0]; 
      for (int i = 1; i < nums.size(); i++)
      {
        int p1 = nums[i] * mx;
        int p2 = nums[i] * mn; 
        mx = max({nums[i], p1, p2});
        mn = min({nums[i], p1, p2});
        answer = max(mx, answer);
      }
      return answer;
    }
};