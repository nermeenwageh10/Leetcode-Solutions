# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        

        dummy=ListNode(0,head)
        prev=dummy
        while prev.next and prev.next.next:
            a,b=prev.next,prev.next.next
            temp= a
            prev.next = b
            a.next,b.next=b.next,a
            prev=temp
        return dummy.next
