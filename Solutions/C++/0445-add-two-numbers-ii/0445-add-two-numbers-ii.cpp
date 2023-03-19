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
    int carray;
    int linkedListSize(ListNode* l)
    {
      int sz = 0;
      ListNode* tm = l; 
      while(tm != nullptr)
      {
        tm = tm->next;
        sz++;
      }
      return sz; 
    }
    void recursive(ListNode* l1, ListNode* l2)
    {
      if (l1->next != nullptr && l2->next != nullptr)
        recursive(l1->next, l2->next); 
    
      if (l1 != nullptr && l2 != nullptr)
      {
        l1->val += l2->val + carray; 
        carray = l1->val / 10;
        l1->val %= 10; 
      }
    }
    void add(ListNode* &l, int val = 0)
    {
      ListNode* cur = new ListNode(val, l);
      l = cur; 
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1 = linkedListSize(l1);
        int s2 = linkedListSize(l2);
      while(s1 < s2)
      {
        add(l1);
        s1++; 
      }
      while(s2 < s1)
      {
        add(l2);
        s2++; 
      }
      carray = 0; 
      recursive(l1, l2); 
      if (carray)
        add(l1, carray); 
      return l1;
    }
};