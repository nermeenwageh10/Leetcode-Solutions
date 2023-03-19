class Solution {
public:
    int dp[1001][1001];
    int solve(string& a, string& b, int i = 0, int j = 0){
        if (i == a.size() || j == b.size()) return 0;
        int& ret = dp[i][j];
        if (~ret) return ret;
        ret = 0;
        if (a[i] == b[j]) ret = 1 + solve(a, b, i + 1, j + 1);
        ret = max(ret, solve(a, b, i + 1, j));
        ret = max(ret, solve(a, b, i, j + 1));
        ret = max(ret, solve(a, b, i+1, j+1));
        return ret;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return solve(text1, text2, 0, 0);
    }
};