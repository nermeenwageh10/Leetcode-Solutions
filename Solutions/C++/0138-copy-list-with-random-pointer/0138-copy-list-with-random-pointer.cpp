/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        map<Node*, Node*> mp;
        Node* root = new Node(head->val);
        mp[head] = root;
        Node* temp = root;
        Node* temp1 = head;
        while (temp1->next){
            temp1 = temp1->next;
            temp->next = new Node(temp1->val);
            mp[temp1] = temp->next;
            temp = temp->next;
        }
        temp = root;
        temp1 = head;
        while (temp1){
            temp->random = mp[temp1->random];
            temp = temp->next;
            temp1 = temp1->next;
        }
        return root;
    }
};