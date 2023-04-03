class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int occurence = count(nums.begin(),nums.end(),val);
        remove(nums.begin(),nums.end(),val);
        return nums.size()-occurence;
        
    }
};
