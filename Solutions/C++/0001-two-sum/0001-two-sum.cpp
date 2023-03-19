class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int,vector<int>> mp ; 
        for (int i =0 ; i < nums.size();i++)
        {
            mp[ nums[i] ].push_back(i) ; 
        }
        sort (nums.begin(),nums.end());
        for (int i =0  , j = nums.size()-1; i < j ;)
        {
            if (nums[i]+nums[j] == target)
            {
                if (nums[i] != nums[j])
                return {mp[nums[i]][0],mp[nums[j]][0]};
                    else 
                return {mp[nums[i]][0],mp[nums[j]][1]};
                    
            }else if (nums[i]+nums[j] > target)
                j--; 
            else 
                i++; 
        }
        return {};
    }
};