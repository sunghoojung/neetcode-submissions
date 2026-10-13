# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        if list2 is None: 
            return list1
        
        ptr1 = list1
        ptr2 = list2
        head = ListNode()

        if (ptr1.val <= ptr2.val):
            head = ptr1
            ptr1 = ptr1.next
        else:
            head = ptr2
            ptr2 = ptr2.next

        prev = head

        while (ptr1 is not None and ptr2 is not None):
            if (ptr1.val <= ptr2.val):
                prev.next = ptr1
                ptr1 = ptr1.next
            else:
                prev.next = ptr2
                ptr2 = ptr2.next
            prev = prev.next
        
        if (ptr1 is not None): prev.next = ptr1
        if (ptr2 is not None): prev.next = ptr2

        return head
        
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists or len(lists) == 0:
            return None

        while (len(lists) > 1):
            mergedLists = []

            for i in range(0, len(lists), 2):
                l1 = lists[i]
                l2 = lists[i+1] if i+1 < len(lists) else None
                mergedLists.append(self.mergeTwoLists(l1, l2))
            lists = mergedLists
        return lists[0]
                 
