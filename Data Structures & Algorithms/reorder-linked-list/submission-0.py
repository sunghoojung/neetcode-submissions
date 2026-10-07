# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head

        prev = None
        curr = head
        ptr = curr.next

        if ptr == None:
            return head

        while (ptr != None):
            temp = ptr
            ptr = ptr.next
            temp.next = curr
            curr.next = prev
            prev = curr
            curr = temp
            
        return curr

    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = head
        fast = head
        while fast is not None and fast.next is not None and fast.next.next is not None:
            slow = slow.next
            fast = fast.next.next


        secondHead = slow.next
        slow.next = None

        reverseHead = self.reverseList(secondHead)

        ptr1 = head
        ptr2 = reverseHead

        while (ptr1 is not None and ptr2 is not None):
            temp = ptr1
            ptr1 = ptr1.next
            temp.next = ptr2
            temp2 = ptr2
            ptr2 = ptr2.next
            temp2.next = ptr1
        

        


        