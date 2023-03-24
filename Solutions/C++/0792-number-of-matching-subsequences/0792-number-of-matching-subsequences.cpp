class Solution {
public:
  int numMatchingSubseq(string s, vector<string>& words) {
    vector<vector<int>> nxt((int)s.size());
    nxt[s.size()-1] = vector<int>(26, -1);
    nxt[s.size()-1][s.back()-'a'] = s.size()-1;
    for (int i = s.size()-2; i >= 0; i--){
      nxt[i] = nxt[i+1];
      nxt[i][s[i]-'a'] = i;
    }
    int cnt = 0;
    for (int i = 0; i < words.size(); i++){
      int index = 0;
      int j = 0;
      while (j < words[i].size() && index < s.size()){
        index = nxt[index][words[i][j] - 'a'];
        if (index == -1) break;
        index++;
        j++;
      }
      cnt += j == words[i].size();
    }
    return cnt;
  }
};