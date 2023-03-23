class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0) continue;
            int j = i + 1;
            while (j < nums.size() && nums[j] == 0)
                j++;
            int len = j - i;
            ans += 1LL * len * (len + 1) / 2;
            i = j;
        }
        return ans;
    }
};