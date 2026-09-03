# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        # what if we make 3 values
        # 1 -> maxima 0 > none -1 -> minima
        # actually, we can make it 1 and 0 
        # then make a 1D array, find the difference min and max using sliding window?

        # first, let's loop
        prev = head
        curr = prev.next
        arr = []
        arr.append(0)
        while curr.next is not None:
            prevVal = prev.val
            currVal = curr.val
            nxVal = curr.next.val
            if prevVal > currVal and nxVal > currVal:
                arr.append(1)
            elif prevVal < currVal and nxVal < currVal:
                arr.append(1)
            else:
                arr.append(0)
            prev = curr
            curr = curr.next
        arr.append(0)
        
        first_idx = -1
        prev_idx = -1
        next_idx = -1
        minimum = float('inf')
        maximum = -1
        for key, val in enumerate(arr):
            if val == 0:
                continue
            if first_idx == -1:
                first_idx = key
                prev_idx = key
                continue
            elif next_idx == -1:
                next_idx = key
            else:
                prev_idx = next_idx
                next_idx = key
            minimum = min(minimum, next_idx - prev_idx)
            maximum = max(maximum, next_idx - first_idx)

        if next_idx == -1:
            return [-1, -1]
        return [minimum,maximum]  

                

        
