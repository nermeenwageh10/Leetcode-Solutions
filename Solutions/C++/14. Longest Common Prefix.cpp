class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        char current;
        int i, j;
        int firstStringLength = strs[0].size(); // take First Word Length as reference
        for(i = 0; i < firstStringLength; i++){
            current = strs[0][i]; // take First Word characters as reference 
            for(j = 1; j < strs.size(); j++){
               if(current != strs[j][i])
                   return common;
            }
            common+=current;
        }
        return common;
    }
};
