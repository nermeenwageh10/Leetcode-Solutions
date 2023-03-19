/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  map<Node*, Node*> mp;
  set<Node*> seen;
  void dfs(Node* node){
    if (node == nullptr) return;
    mp[node] = new Node(node->val);
    for (int i = 0; i < node->neighbors.size(); i++){
      if (mp.find(node->neighbors[i]) == mp.end())
        dfs(node->neighbors[i]);
    }
  }
  void build(Node* newGraph, Node* oldGraph){
    if (oldGraph == nullptr) return;
    seen.insert(newGraph);
    for (int i = 0; i < oldGraph->neighbors.size(); i++){
      newGraph->neighbors.push_back(mp[oldGraph->neighbors[i]]);
      if (seen.find(newGraph->neighbors.back()) != seen.end()) continue;
      build(newGraph->neighbors.back(), oldGraph->neighbors[i]);
    }
  }
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    mp = map<Node*, Node*>();
    seen = set<Node*>();
    dfs(node);
    Node* root = mp[node];
    build(root, node);
    return root;
  }
};