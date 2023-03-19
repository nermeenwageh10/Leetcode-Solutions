class Solution {
public:
    int search(vector<int>& nums, int l, int r, int target){
        int m;
        while (l <= r){
            m = (l+r) >> 1;
            if (nums[m] == target) 
                return m;
            if (nums[m] < target)
                l = m + 1;
            else 
                r = m - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        /*
        1 2 3 4 5 6 
        6 1 2 3 4 5
        5 6 1 2 3 4
        4 5 6 1 2 3
        3 4 5 6 1 2
        2 3 4 5 6 1
        */
        if (nums.size() == 1){
            return nums[0] == target? 0: -1;
        }
        int k = -1;
        if (nums[0] > nums.back()){
            int l = 1, r = nums.size()-1, m;
            while (l <= r){
                m = (l+r) >> 1;
                if (nums[m] > nums[0]){
                    k = m;
                    l = m + 1;
                }else {
                    r = m - 1;
                }
            }
            if (k == -1) 
                k = 0;
        }
        cout << k << "\n";
        if (k == -1)
            return search(nums, 0, (int)nums.size()-1, target);
        else {
            int curIndex = search(nums, 0, k, target);
            if (curIndex != -1) return curIndex;
            return search(nums, k+1, (int)nums.size()-1, target);
        }
    }
};