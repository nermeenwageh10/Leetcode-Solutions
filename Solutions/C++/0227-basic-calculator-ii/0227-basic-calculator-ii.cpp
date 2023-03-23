class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char lstChar = '+';
        int number = 0;
        for (int i = 0; i < s.size(); i++){
            
            bool compute = 1;
            if (isdigit(s[i])){
                while (i < s.size() && isdigit(s[i])){
                    number = number * 10 + (s[i] - '0');
                    i++;
                }
                if (i == s.size())
                    compute = 1;
                i--;
            }
            if (compute && (i == s.size() || s[i] != ' ')){
                int num;
                switch(lstChar){
                    case '+':
                        stk.push(number);
                        break;
                    case '-':
                        stk.push(-number);
                        break;
                    case '/':
                        num = stk.top();stk.pop();
                        stk.push(num / number);
                        break;
                    case '*':
                        num = stk.top();stk.pop();
                        stk.push(num * number);
                        break;
                }
                lstChar = s[i];
                number = 0;
            }
            
        }
        int value = 0;
        while (stk.size()){
            value += stk.top();
            stk.pop();
        }
        return value;
    }
};