class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        alloc = []
        for key, val in enumerate(ratings):
            if not alloc:
                alloc.append(1)
                continue
            if ratings[key - 1] < val:
                alloc.append(alloc[-1] + 1)
            else:
                alloc.append(1)
        

        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                alloc[i] = max(alloc[i + 1] + 1, alloc[i])
        return sum(alloc)

# [1, 0, 2]
# [1, 1, 2]
# [ , 1, 2]
