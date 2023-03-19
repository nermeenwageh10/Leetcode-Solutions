class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 1e9;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1, k = nums.size()-1; j < k;)
            {
                int sum = nums[i] + nums[j] + nums[k]; 
                if (abs(target - sum) < abs(target - ans))
                    ans = sum;
                if (sum == target)
                {
                    return target; 
                }else if (sum > target)
                {
                    k--;
                }else 
                {
                    j++;                    
                }
            }
        }
        return ans;
    }
};