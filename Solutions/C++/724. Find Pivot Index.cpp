class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int TotalSum = accumulate(nums.begin(),nums.end(),0);
        int RightSum = 0, LeftSum = 0;
        for(int i = 0; i < nums.size();i++){
            if(i > 0){
            LeftSum+= nums[i-1];
            }
            RightSum = TotalSum - nums[i] - LeftSum;
            if(LeftSum == RightSum)
                return i;
        }
        return -1;
    }
};
