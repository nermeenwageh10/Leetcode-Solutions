class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret(nums.size(), 1);
        for(int _ = 0; _ < 2; _++)
        {
          int prd = 1;
          for(int i = 0; i < nums.size(); i++)
          {
              ret[_? nums.size()-1-i: i] *= prd; 
              prd *= nums[_? nums.size()-1-i: i];
          }
        }
        return ret;
    }
};