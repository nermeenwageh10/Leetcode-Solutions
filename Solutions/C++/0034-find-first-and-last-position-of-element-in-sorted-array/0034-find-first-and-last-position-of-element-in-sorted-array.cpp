class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid, F = -1, L = -1;
        while(l <= r)
        {
            mid = (l+r) >> 1;
            if (nums[mid] >= target)
                F = mid, r = mid - 1;
            else 
                l = mid + 1;
        }
        if (F == -1 || nums[F] != target)
            return {-1, -1};
        l = F, r = nums.size() - 1;
        while(l <= r)
        {
            mid = (l+r) >> 1;
            if (nums[mid] <= target)
                L = mid, l = mid + 1;
            else 
                r = mid - 1;
        }
        return {F, L};
    }
};