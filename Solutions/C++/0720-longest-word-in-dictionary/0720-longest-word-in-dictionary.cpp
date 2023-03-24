class Trie {
  struct Node {
    bool isLeaf;
    vector<int> next;
    Node(){
      isLeaf = 0;
      next = vector<int>(26, -1);
    }
  };
  vector<Node> root;
public:
  Trie(){
    root.push_back(Node());
  }
  void insert(string s){
    int index = 0;
    for (int i = 0; i < s.size(); i++){
      int pos = s[i] - 'a';
      if (root[index].next[pos] == -1){
        root[index].next[pos] = root.size();
        root.push_back(Node());
      }
      index = root[index].next[pos];
    }
    root[index].isLeaf = 1;
  }
  string getMaxCommonPrefixHelper(int index){
    string cur = "";
    for (int i = 0; i < 26; i++){
      int nxt = root[index].next[i];
      if (nxt != -1 && root[nxt].isLeaf){
        string ret = char('a' + i) + getMaxCommonPrefixHelper(nxt);
        if (ret.size() > cur.size() ||
        (ret.size() == cur.size() && ret < cur)){
          cur = ret;
        }
      }
    }
    return cur;
  }
  string getMaxCommonPrefix(){
    return getMaxCommonPrefixHelper(0);
  }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (int i = 0; i < words.size(); i++)
            trie.insert(words[i]);
        return trie.getMaxCommonPrefix();
    }
};