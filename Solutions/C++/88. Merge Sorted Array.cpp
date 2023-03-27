class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j = 0;
        for(i = m, j = 0; j < n; i++,j++){
            nums1[i] = nums2[j];
        }
        sort(nums1.begin(), nums1.end());
    }
};
