class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string x = to_string(a);
            string y = to_string(b);
            return x+y > y+x;
        });
        string ret = "";
        for (int i = 0; i < nums.size(); i++)
            ret += to_string(nums[i]);
        while (ret[0] == '0' && ret.size() > 1)
            ret = ret.substr(1);
        return ret;
    }
};