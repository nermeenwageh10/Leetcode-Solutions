class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = vector<vector<int>>(matrix.size());
        for (int i = 0; i < matrix.size(); i++){
            prefix[i] = vector<int>(matrix[i].size(), 0);
            for (int j = 0; j < matrix[i].size(); j++){
                prefix[i][j] = matrix[i][j];
                if (i-1 >= 0) prefix[i][j] += prefix[i-1][j];
                if (j-1 >= 0) prefix[i][j] += prefix[i][j-1];
                if (i-1>=0&&j-1>=0) prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        if (col1-1>=0)
        total -= prefix[row2][col1-1];
        if (row1-1>=0)
        total -= prefix[row1-1][col2];
        if (row1-1>=0&&col1-1>=0)
        total += prefix[row1-1][col1-1];
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */