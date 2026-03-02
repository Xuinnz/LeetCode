class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals:
            return [newInterval]
        elif newInterval[1] < intervals[0][0]:
            return [newInterval] + intervals
        elif newInterval[0] > intervals[-1][1]:
            return intervals + [newInterval]
        res = []
        n = len(intervals)
        i = 0
        while i < n - 1 and newInterval[0] > intervals[i][1]:
            res.append([intervals[i][0], intervals[i][1]])
            i += 1
        if i < n and newInterval[0] > intervals[i - 1][1] and newInterval[1] < intervals[i][0]:
            res.append([newInterval[0], newInterval[1]])
            res = res + intervals[i:]
            return res 
        newStart = min(intervals[i][0], newInterval[0])
        while i < n - 1 and newInterval[1] >= intervals[i + 1][0]:
            i += 1
        newEnd = max(intervals[i][1], newInterval[1])
        res.append([newStart, newEnd])
        i += 1
        while i < n:
            res.append([intervals[i][0], intervals[i][1]])
            i += 1
        return res
            
        
