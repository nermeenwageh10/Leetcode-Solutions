class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix = vector<int> (nums.size(), 0);
        for (int i = 0; i < nums.size(); i++){
            prefix[i] = nums[i] + (i? prefix[i-1]: 0);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right] - (left? prefix[left - 1]: 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */