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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prv = nullptr; 
        ListNode* temp = head; 
        bool first = 1; 
        while(head != nullptr && head->next != nullptr)
        {
            ListNode* cur = head; 
            head = head->next; 
            ListNode* nxt = head->next;
            
            if (prv != nullptr)
            {
                prv->next = head;  
            }
            head->next = cur; 
            if (first)temp = head; 
            first = 0;
            cur->next = nxt; 
            prv = cur;
            head = cur->next; 
        }
        return temp; 
    }
};