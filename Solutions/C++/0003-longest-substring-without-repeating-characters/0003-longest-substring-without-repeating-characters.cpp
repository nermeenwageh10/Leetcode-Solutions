class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if (s.size() == 0)return 0;
      int answer = 1;
      int l = 0, r = 0;
      map<char, int> mp;
      mp[s[0]]++;
      while(r < s.size())
      {
        while(r + 1 < s.size() && mp[s[r+1]] == 0)
        {
          r++;
          mp[s[r]]++; 
        }
        answer = max(answer, r - l + 1); 
        if (l == r)
        {
          mp[s[l]]--; 
          l++;r++;
          if (l < s.size())mp[s[l]]++;
        }else 
          mp[s[l++]]--;
      }
      return answer; 
        
        
    }
};