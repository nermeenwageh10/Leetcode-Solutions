class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bitset<100001> frequency= {0};
        int i;
        for(int num: nums){
            if(frequency[num])
                return num;
            else
                frequency[num] = 1;
        }
        return 0;
    }
};
