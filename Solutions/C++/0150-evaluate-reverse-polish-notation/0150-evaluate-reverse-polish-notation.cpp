class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for (int i = 0; i < tokens.size(); i++){
            bool in = 0;
            string op = "-+*/";
            for (int j = 0; j < 4; j++)
                if (tokens[i].size() == 1 && tokens[i][0] == op[j])
                 in = 1;
            if (!in){
                stk.push(tokens[i]);
            }else {
                assert(stk.size() > 1);
                long long n2 = stoul(stk.top());stk.pop();
                long long n1 = stoul(stk.top());stk.pop();
                long long ret = 0;
                switch(tokens[i][0]){
                    case '+':
                        ret = n1 + n2;
                        break;
                    case '-':
                        ret = n1 - n2;
                        break;
                    case '*':
                        ret = n1 * n2;
                        break;
                    case '/':
                        ret = n1 / n2;
                        break;
                }
                stk.push(to_string(ret));
            }
        }
        return stoi(stk.top());
    }
};