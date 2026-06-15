class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:

        lowest = 3000
        for i, n in enumerate(landStartTime):
            for j, m in enumerate(waterStartTime):
                #case 1: land -> water
                landEnd = n + landDuration[i]
                if landEnd < m:
                    landEnd = m
                if lowest > (landEnd + waterDuration[j]):
                    lowest = (landEnd + waterDuration[j])

                #case 2: water -> land
                waterEnd = m + waterDuration[j]
                if waterEnd < n:
                    waterEnd = n
                if lowest > (waterEnd + landDuration[i]):
                    lowest = (waterEnd + landDuration[i])
        return lowest
