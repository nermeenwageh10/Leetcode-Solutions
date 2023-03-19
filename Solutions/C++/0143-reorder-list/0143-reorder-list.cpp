/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     
    void reorderList(ListNode* head) {
        ListNode* root = head;
        deque<int> v;
        while (head){
            v.push_back(head->val);
            head = head->next;
        }
        head = root;
        while (head){
            head->val = v.front();
            v.pop_front();
            head = head->next;
            if (v.size()){
                head->val = v.back();
                v.pop_back();
                head = head->next;
            }
        }
        head = root;
    }
};