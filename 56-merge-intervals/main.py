class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        #[[2,3],[4,5],[6,7],[8,9],[1,10]]
        intervals.sort()
        #[[1,10],[2,3],[4,5],[6,7],[8,9]]
        n = len(intervals)
        i = 0
        j = 0
        while i < n:
            start = intervals[i][0]
            end = intervals[i][1]
            while i < n - 1 and end >= intervals[i + 1][0]:
                i += 1
                end = max(end, intervals[i][1])
            res.append([start, end])
            j += 1
            i += 1
            
        return res
