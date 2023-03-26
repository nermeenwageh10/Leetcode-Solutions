class Solution {
public:
    vector <string> ans ;
    void GenerateParentheses(string current, int openCount, 
                             int closeCount, int remainingCount, int n)
    {
        if (remainingCount == 0)
        {
            ans.push_back(current);
            return;
        }

        if (current.size() > 2 * n)
        {
            return;
        }

        if (openCount < n)
        {
            GenerateParentheses(current + "(", openCount + 1, closeCount, remainingCount, n);
        }

        if (closeCount < openCount)
        {
            GenerateParentheses(current + ")", openCount, closeCount + 1, remainingCount - 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
     GenerateParentheses("",0,0,n,n);
     return ans; 
        
    }
};