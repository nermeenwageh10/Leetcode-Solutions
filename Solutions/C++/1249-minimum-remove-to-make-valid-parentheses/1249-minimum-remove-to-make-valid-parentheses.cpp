class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str = "";
        int open = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                open++;
                str += '(';
            }else if (s[i] == ')'){
                if (open){
                    str += ')';
                    open--;
                }
            }else {
                str += s[i];
            }
        }
        stack<char> addAtEnd;
        while (open > 0){
            while (str.back() != '('){
                addAtEnd.push(str.back());
                str.pop_back();
            }
            str.pop_back();
            open--;
        }
        while (addAtEnd.size()){
            str += addAtEnd.top();
            addAtEnd.pop();
        }
        return str;
    }
};