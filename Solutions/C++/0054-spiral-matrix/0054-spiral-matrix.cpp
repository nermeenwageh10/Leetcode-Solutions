class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top_row = 0, left_col = 0, lower_row = matrix.size()-1, right_col = matrix[0].size()-1;
        vector<int> ret; 
        while(top_row <= lower_row && left_col <= right_col)
        {
           
            for(int i = left_col; i <= right_col; i++)
            {
                ret.push_back(matrix[top_row][i]);
            }
            if (top_row == lower_row)break;
            for(int i = top_row+1; i <= lower_row; i++)
            {
                ret.push_back(matrix[i][right_col]); 
            }
            for(int i = right_col-1; i >= left_col; i--)
            {
                ret.push_back(matrix[lower_row][i]); 
            }
            if (left_col == right_col)break;
            for(int i = lower_row-1; i > top_row; i--)
            {    
                ret.push_back(matrix[i][left_col]); 
            }
            top_row++;left_col++;
            lower_row--;right_col--;
        }
        return ret;
    }
};