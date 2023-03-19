class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n , m ; 
        n = nums1.size(); 
        m = nums2.size(); 
        if (n==0)
        {
            if (m%2)
            {
                return nums2[m/2] ; 
            }else 
            {
                return (nums2[m/2] + nums2[m/2-1])/2.0 ; 
            }
        }else if (m==0)
        {
            if (n%2)
            {
                return nums1[n/2] ; 
            }else 
            {
                return (nums1[n/2] + nums1[n/2-1])/2.0 ; 
            }
        }
        vector <int> big (n+m); 
        for (int i =0 , j =0,k=0 ; i < n || j < m ;k++)
        {
            if (i >= n )
            {
                big[k] = nums2[j];
                j++;
                continue ;
            }else if (j >= m )
            {
                big[k] = nums1[i]; 
                i++;
                continue ;
            }
            if (nums1[i] <= nums2[j])
            {
                big[k] = nums1[i]; 
                i++;
            }else 
            {
                big[k] = nums2[j]; 
                j++; 
            }
            
        }
        n+=m;
        if (n%2)
            return big[n/2]; 
        else 
            return (big[n/2]+big[n/2-1])/2.0 ; 
    }
};