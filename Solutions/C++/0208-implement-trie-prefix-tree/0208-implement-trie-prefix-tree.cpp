class Trie {
public:
    struct TrieNode{
      bool isWord = 0;
      vector<int> next;
    };
    vector<TrieNode> root;
    Trie() {
        root.push_back(TrieNode());
        root[0].next = vector<int>(26, -1);
    }
    
    void insert(string word) {
        int cur = 0;
        for (int i = 0; i < word.size(); i++){
            if (root[cur].next[word[i] - 'a'] == -1){
                root[cur].next[word[i] - 'a'] = root.size();
                root.push_back(TrieNode());
                root.back().next = vector<int>(26, -1);
            }    
            cur = root[cur].next[word[i] - 'a'];
        }
        root[cur].isWord = 1;
    }
    
    bool search(string word) {
        int cur = 0;
        for (int i = 0; i < word.size(); i++){
            if (root[cur].next[word[i] - 'a'] == -1){
                return 0;
            }    
            cur = root[cur].next[word[i] - 'a'];
        }
        return root[cur].isWord;
    }
    
    bool startsWith(string prefix) {
        int cur = 0;
        for (int i = 0; i < prefix.size(); i++){
            if (root[cur].next[prefix[i] - 'a'] == -1){
                return 0;
            }    
            cur = root[cur].next[prefix[i] - 'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */