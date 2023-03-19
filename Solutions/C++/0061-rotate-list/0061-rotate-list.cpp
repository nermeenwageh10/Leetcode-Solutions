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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)return head; 
        ListNode* tail = head; 
        int sz = 1;
        while(tail->next)
        {
            tail = tail->next; 
            sz++;
        }
        tail->next = head; 
        k %= sz; 
        k = sz - k; 
        while(k--)
        {
            tail = head; 
            head = head->next;
        }
        tail->next = nullptr;
        return head;
        
    }
};