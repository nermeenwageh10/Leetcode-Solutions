class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++){
            // check if this is the begining of the streak
            if (st.count(nums[i] - 1) == 0){
                int cur = 1;
                int num = nums[i] + 1;
                while (st.count(num)){
                    cur++;
                    num++;
                }
                longest = max(longest, cur);
            }
        }
        return longest;
    }
};