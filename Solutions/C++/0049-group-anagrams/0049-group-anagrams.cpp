class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<pair<string, string>> tem;
      
      for (int i = 0; i < strs.size(); i++)
      {
        string cur = strs[i];
        sort(cur.begin(), cur.end()); 
        tem.push_back({cur, strs[i]}); 
      }
      sort(tem.begin(), tem.end()); 
      vector<vector<string>> ret; 
      vector<string> cur;
      for (int i = 0; i < strs.size(); i++)
      {
        cur.clear();
        cur.push_back(tem[i].second);
        int j = i+1;
        while(j < strs.size() && tem[j].first == tem[i].first)
        {
          cur.push_back(tem[j].second); 
          j++; 
        }
        i = j-1; 
        ret.push_back(cur); 
      }
      return ret; 
    }
};