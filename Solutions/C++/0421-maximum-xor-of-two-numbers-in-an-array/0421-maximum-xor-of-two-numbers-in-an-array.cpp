class Trie {
  struct Node {
    bool isLeaf;
    vector<int> next;
    Node(){
      isLeaf = 0;
      next = vector<int>(2, -1);
    }
  };
  vector<Node> trie;
  public:
    Trie(){
      trie.push_back(Node());
    }
    void insert(int value){
      int rootIndex = 0;
      for (int i = 30; i > -1; i--){
        int isSet = (value & (1<<i)) != 0;
        if (trie[rootIndex].next[isSet] == -1){
          trie[rootIndex].next[isSet] = trie.size();
          trie.push_back(Node());
        }
        rootIndex = trie[rootIndex].next[isSet];
      }
      trie[rootIndex].isLeaf = 1;
    }
    int getMax(int value){
      int mx = 0, root = 0;
      for (int i = 30; i >= 0; i--){
        int isSet = (value & (1<<i)) != 0;
        if (trie[root].next[!isSet] != -1){
          mx |= (1<<i);
          root = trie[root].next[!isSet];
        }else {
          root = trie[root].next[isSet];
        }
      }
      return mx;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int i = 0; i < nums.size(); i++) 
            trie.insert(nums[i]);
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
            mx = max(mx, trie.getMax(nums[i]));
        return mx;
    }
};