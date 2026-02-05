class Solution:
    def search(self, nums: List[int], target: int) -> int:
        count = len(nums)
        start = 0
        end = count - 1
        mid = (start + end) // 2
        while start <= end:
            if target == nums[mid]:
                return mid
            if target == nums[start]: return start
            if target == nums[end]: return end
            elif nums[start] <= nums[end] and target < nums[mid]: #normal 
                end = mid - 1
            elif nums[start] <= nums[end] and target > nums[mid]: #normal 
                start = mid + 1
            elif nums[start] <= nums[mid] and (target > nums[mid] or target < nums[start]): 
                start = mid + 1
            elif nums[start] <= nums[mid] and (target < nums[mid] and target >= nums[start]):
                end = mid - 1
            elif nums[start] > nums[mid] and (target < nums[mid] or target > nums[end]):
                end = mid - 1
            elif nums[start] > nums[mid] and (target > nums[mid] and target <= nums[end]):
                start = mid + 1
            
            if (((start + end) // 2) == mid):
                break
            mid = (start + end) // 2
        return -1