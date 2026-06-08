class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less = []
        same = []
        great = []
        for i, n in enumerate(nums):
            if n < pivot:
                less.append(n)
            elif n > pivot:
                great.append(n)
            else:
                same.append(n)
        return less + same + great
