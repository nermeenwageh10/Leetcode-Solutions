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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* tem = head ;ListNode* prv = head  ; 
    int sz = 0 ; 
    while (tem!= NULL)tem = tem->next , sz++ ;
    
    int rm = sz - n + 1;  
    tem = head ; 
    if (rm == 1 )return head->next ;
    while (--rm)
    {
        prv = tem ; 
        tem = tem->next ; 
    }
    
    prv -> next = tem -> next ; 
    return head ;
    }
};