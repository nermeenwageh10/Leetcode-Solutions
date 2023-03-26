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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head  == nullptr || head->next == nullptr || left == right) return head;
        int pos = 1;
        ListNode* prv = nullptr;
        ListNode* cur = head;
        ListNode* first = nullptr;
        ListNode* last = nullptr;
        ListNode* lastInRange = nullptr;
        ListNode* firstInRange = nullptr;
        while(head != nullptr)
        {
            if (pos + 1 == left)
                first = head;
            if (pos == right + 1)
            {
                last = head;
                break;
            }
            if (pos >= left && pos <= right)
            {
                if (pos == left)
                    lastInRange = head;
                
                ListNode* nxt = head->next;
                /*
                
                nxt = 2 
                fir -> 1 -> -
                head = 2 -> 1 
                */
                head->next = prv;
                firstInRange = head;
                prv = head;
                head = nxt;
            }else 
            {
                prv = head;
                head = head->next;
            }
            pos++;
        }
        if (first && firstInRange)
            first->next = firstInRange;
        else 
            cur = firstInRange;
        
        if (lastInRange)
            lastInRange->next = last;
        
        
        return cur;
        
    }
};