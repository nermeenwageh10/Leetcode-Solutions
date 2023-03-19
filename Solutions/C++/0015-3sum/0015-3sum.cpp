class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ret;
        map<array<int, 3>, bool> seen; 
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1, k = nums.size()-1; j < k; )
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    if (seen.find({nums[i], nums[j], nums[k]}) == seen.end())
                    {
                        seen[{nums[i], nums[j], nums[k]}] = 1; 
                        ret.push_back({nums[i], nums[j], nums[k]});
                    }
                    j++;k--; 
                }else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else 
                    j++;
            }
        }
        return ret;
    }
};