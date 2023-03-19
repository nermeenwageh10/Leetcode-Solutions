class Solution {
public:
    int area (vector<int>& height , int i , int j )
    {
        return (1LL*(j-i)*min(height[i],height[j]));
    }
    int maxArea(vector<int>& height) {
        int ans =0 ; 
        for (int i =0 , j = height.size()-1; i < j;)
        {
            ans = max (ans , area(height,i,j)); 
            if (height[i] <= height[j])
                i++; 
            else 
                j--; 
        }
    
    return ans ;
    }
};