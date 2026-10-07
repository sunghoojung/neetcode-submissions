# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        ptr1 = l1
        ptr2 = l2
        new_head = None
        tail = None
        carry = 0

        while ptr1 is not None or ptr2 is not None or carry:
            val1 = ptr1.val if ptr1 is not None else 0
            val2 = ptr2.val if ptr2 is not None else 0

            num = val1 + val2 + carry
            lastDigit = num % 10
            carry = num // 10

            new_node = ListNode(lastDigit)

            if new_head is None:
                new_head = new_node
            else:
                tail.next = new_node

            tail = new_node

            if ptr1 is not None:
                ptr1 = ptr1.next
            if ptr2 is not None:
                ptr2 = ptr2.next

        return new_head
        