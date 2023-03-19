class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size(); 
        for(int rep = 0; rep < 3; rep++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n - j - 1; j++)
                    swap(mat[i][j], mat[i][n-j-1]); 
            }
            for(int i = 0; i < n; i++)
                for(int j = i; j < n; j++)
                    swap(mat[i][j], mat[j][i]);
        }
    }
};