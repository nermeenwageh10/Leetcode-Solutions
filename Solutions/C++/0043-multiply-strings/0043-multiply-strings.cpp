class Solution {
public:
    string multiply(string num1, string num2) {
        string ret = ""; 
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < num1.size(); i++)
        {
            string cur = string(i, '0'); 
            int carry = 0;
            for(int j = 0; j < num2.size(); j++)
            {
                int prd = (num1[i] - '0') * (num2[j] - '0') + carry;  
                cur += (prd % 10) + '0'; 
                carry = prd / 10; 
            }
            cur += carry + '0'; 
            carry = 0;
            while(ret.size() < cur.size())ret += "0"; 
            string sum = "";
            for(int j = 0; j < ret.size(); j++)
            {
                int add = (cur[j]-'0') + (ret[j] - '0') + carry; 
                sum += (add % 10) + '0';
                carry = add / 10;
            }
            sum += carry + '0';
            ret = sum;
        }
        while(ret.back() == '0' && ret.size() > 1)ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }
};