class Solution {
public:
    int dp[101];
    int solve(string& s, int i = 0)
    {
        if (i == s.size())
            return 1;
        int &ret = dp[i];
        if (~ret) return ret;
        if (s[i] == '0') return ret = 0;
        ret = solve(s, i + 1);
        if ( i + 1 < s.size() && (s[i] - '0') * 10 + (s[i+1] - '0') <= 26)
            ret += solve(s, i + 2);
        return ret;
    }
    int numDecodings(string s) {
     memset(dp, -1, sizeof dp);
     return solve(s);
    }
};