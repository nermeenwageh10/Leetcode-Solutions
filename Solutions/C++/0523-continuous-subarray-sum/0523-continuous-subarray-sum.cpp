class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 0;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++){
            pre = (pre + nums[i])%k;
            if (mp.find(pre) == mp.end())
                mp[pre] = i + 1;
            else if (mp[pre] < i)
                return 1;
        }
        return 0;
    }
};