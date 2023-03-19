class Solution {
public:
    int minOperations(vector<int>& nums) {
        int mn = 1e9, n = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        for (int i = 0; i < nums.size(); i++){
            int lst = nums[i] + n - 1;
            int l = i, r = nums.size()-1, m, index = i;
            while (l <= r){
                m = (l+r) >> 1;
                if (nums[m] <= lst){
                    index = m;
                    l = m + 1;
                }else 
                    r = m - 1;
            }
            mn = min(mn, n - (index - i + 1));
        }
        return mn;
    }
};