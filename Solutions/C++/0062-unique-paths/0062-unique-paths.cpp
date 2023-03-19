class Solution {
public:
    int  C[200][100]; 
    int  PC (int x , int y )
    {
        if (x < 0 || y < 0 )return 0 ; 
        if (x == 0 && x == y )return 1 ;
        int &ret = C [x][y]; 
        if (ret != -1 )return ret ; 
        return ret = PC (x-1 , y ) + PC (x , y-1 ); 
    }
    int uniquePaths(int m, int n) {
     memset (C , -1 , sizeof C ); 
     C[0][0] = 1; 
     n--;
     m--; 
     PC (n , m ); 
     
    return C[n][m];
    }
};