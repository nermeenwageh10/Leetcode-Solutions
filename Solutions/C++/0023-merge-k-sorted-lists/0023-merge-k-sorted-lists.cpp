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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = NULL, *head = NULL;
        if (lists.size() == 0) return ret;
        priority_queue<pair<int, ListNode*>> pq;
        for (int i = 0; i < lists.size(); i++){
            if (lists[i] != NULL){
                pq.push({-lists[i]->val, lists[i]});
            }
        }
        
        ret = new ListNode(0);
        head = ret;
        ListNode* prv = NULL;
        while (pq.size()){
            auto cur = pq.top();
            pq.pop();
            int nextValue = -cur.first;
            auto node = cur.second;
            ListNode* temp = node;
            node = node->next;
            delete temp;
            if (node != NULL)
                pq.push({-node->val, node});
            ret->val = nextValue;
            ret->next = new ListNode(0);
            prv = ret;
            ret = ret->next;
        }
        if (prv != NULL) 
            prv->next = NULL;
        else 
            head = NULL;
        return head;
    }
};