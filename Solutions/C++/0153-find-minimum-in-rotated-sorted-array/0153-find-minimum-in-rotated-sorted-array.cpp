class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int rootingPoint = (n > 1? 1: 0);
        
        int l = 0, r = n-1, m;
        while (l <= r){
            m = (l+r) >> 1;
            if (nums[m] >= nums[0]){
                // first half 
                rootingPoint = (m + 1) % n;
                l = m + 1;
            }else 
                r = m - 1;
        }
        
        return min(nums[0], nums[rootingPoint]);
    }
};
/*
0 1 2 3 4 5
5 0 1 2 3 4 
4 5 0 1 2 3
3 4 5 0 1 2
*/