class Solution {
public:
    bool can[305][1001];
    int dp[305], sz; 
    int solve(vector<string>& wordDict, int i)
    {
      if (i == sz)return 1;
      int &ret = dp[i];
      if (~ret)return ret;
      ret = 0;
      for (int j = 0; !ret && j < wordDict.size(); j++)
        if (can[i][j])
          ret = solve(wordDict, i + wordDict[j].size());
      return ret; 
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      memset(can, 0, sizeof can);
      memset(dp, -1, sizeof dp);
      sz = s.size();
      for (int i = 0; i < sz; i++)
      {
        for (int j = 0; j < wordDict.size(); j++)
        {
          if (wordDict[j].size() > sz - i)continue;
          if (s.substr(i, wordDict[j].size()) == wordDict[j])
            can[i][j] = 1; 
        }
      }
      return solve(wordDict, 0) == 1; 
    }
};