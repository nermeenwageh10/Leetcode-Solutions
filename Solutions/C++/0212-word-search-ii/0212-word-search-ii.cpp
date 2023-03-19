#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:  
    static const int K = 26;
    struct Vertext
    {
        int next[K];
        bool leaf = false;
        Vertext()
        {
            memset(next, -1, sizeof next);
        }
    };
    vector<Vertext> trie; 
    void addString(string x)
    {
        int index = 0;
        for(char c: x)
        {
            if (!~trie[index].next[c - 'a'])
            {
                trie[index].next[c-'a'] = trie.size();
                trie.push_back(Vertext());
            }
            index = trie[index].next[c - 'a'];
        }
        trie[index].leaf = 1;
    }
    int vis[13][13], vis_id;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<string> ret;
    string cur;
    void dfs(vector<vector<char>>& board, int x, int y, int ptr)
    {
      if (trie[ptr].leaf)
      {
        ret.push_back(cur);
        trie[ptr].leaf = 0;
        // to not take it again
      }
    
      for(int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (min(nx, ny) < 0 || nx >= board.size() || ny >= board[0].size() || 
            vis[nx][ny] == vis_id)
          continue; 
        int c = board[nx][ny] - 'a';
        if (trie[ptr].next[c] != -1)
        {
            vis[nx][ny] = vis_id;
            cur += board[nx][ny];
            dfs(board, nx, ny, trie[ptr].next[c]);
            cur.pop_back();
            vis[nx][ny] = vis_id - 1;
        }
      }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
      trie = vector<Vertext>(1);  
      for(string& word: words)
        addString(word);  
      cur = "";
      for (int i = 0; ret.size() < words.size() && i < board.size(); i++)
        for (int j = 0; ret.size() < words.size() && j < board[0].size(); j++)
        {
            int c = board[i][j] - 'a';
            if (trie[0].next[c] != -1)
            {
                vis_id++;
                vis[i][j] = vis_id;
                cur += board[i][j];
                dfs(board, i, j, trie[0].next[c]);
                cur = "";
            }
        } 
    
    return ret;
    }
};