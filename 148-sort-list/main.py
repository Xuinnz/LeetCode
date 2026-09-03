# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        arr = []
        while curr:
            arr.append(curr.val)
            curr = curr.next
        arr.sort()

        dummy = ListNode(0)
        tail = dummy
        for val in arr:
            tail.next = ListNode(val)
            tail = tail.next
        return dummy.next
