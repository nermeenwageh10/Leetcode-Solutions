class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        stk.push(num[0]);
        for (int i = 1; i < num.size(); i++){
            while (k && !stk.empty() && num[i] < stk.top()){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while (stk.size() && k){
            k--;
            stk.pop();
        }
        string ret = "";
        while (!stk.empty()){
            ret += stk.top();
            stk.pop();
        }
        while (ret.size() > 0 && ret.back() == '0') 
            ret.pop_back();
        reverse(ret.begin(), ret.end());
        if (ret.size() == 0) ret += "0";
        return ret;
    }
};