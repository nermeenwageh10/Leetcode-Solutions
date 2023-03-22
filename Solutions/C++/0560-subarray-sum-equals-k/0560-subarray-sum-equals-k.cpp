class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int cnt = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            pre += nums[i]; 
            cnt += mp[pre - k];
            mp[pre]++;
            
        }
        return cnt;
    }
};