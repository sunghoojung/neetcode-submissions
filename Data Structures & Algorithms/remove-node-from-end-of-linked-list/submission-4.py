# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0
        ptr = head
        while (ptr != None):
            length += 1
            ptr = ptr.next
        if (n == 1 and length == 1):
            return

        index = length - n 
        i = 1 
        ptr = head
        if (index == 0):
            head = ptr.next
            return head
        while (i != index):
            i += 1
            ptr = ptr.next
        ptr.next = ptr.next.next

        return head
