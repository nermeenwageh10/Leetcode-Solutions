class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(index < nums.size())
            if(nums[index] == target)
            return index;
        return -1;
    }
    
};
