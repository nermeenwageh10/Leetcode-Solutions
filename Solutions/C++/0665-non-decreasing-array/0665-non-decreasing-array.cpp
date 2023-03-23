class Solution {
public:
    bool checkPossibility(vector<int>& nums) { 
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            while (j < nums.size() && nums[j] >= nums[j-1])
                j++;
            if (j == nums.size()) return 1;
            int k = j + 1;
            while (k < nums.size() && nums[k] >= nums[k-1])
                k++;
            if (k != nums.size()) return 0;
            //[0:j-1] [j:k-1]
            // nums[j-1] > nums[j]
            int temp = nums[j];
            nums[j] = nums[j-1];
            if (j + 1 == nums.size() || nums[j] <= nums[j+1])
                return 1;
            nums[j-1] = temp;
            if (j-2 < 0 || nums[j-2] <= nums[j-1])
                return 1;
            return 0;
        }
        return 0;
    }
};