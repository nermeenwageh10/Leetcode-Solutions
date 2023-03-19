 ListNode* curr = head;
        ListNode* temp,*prev=NULL;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
