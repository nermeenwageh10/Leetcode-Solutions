/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode(0) ; 
    ListNode* Head = ans ; 
    
    int carray = 0 ; 
    int sum = 0 ; 
    while (l1 != nullptr || l2 != nullptr  )
    {
        sum =0 ; 
        if (l1 != nullptr )
        {
            sum += l1->val ; 
            l1 = l1->next ; 
        }
        if (l2 != nullptr )
        {
            sum += l2->val;
            l2 = l2->next ; 
        }
        sum+=carray ; 
        ans->val = sum %10; 
        carray = sum/10; 
        if (l1 == nullptr && l2 == nullptr) {
            if (carray != 0 )
            ans->next = new  ListNode(carray);        
            break;
        } 
        ans->next = new  ListNode(0);
        ans = ans -> next ; 
    }
    ans = Head ; 
    return ans ; 
    }
    };