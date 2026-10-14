class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        # 1 min = 6 degrees
        # 5 mins = 30 degrees
        # 15 mins = 90 degrees
        # per 1 min, 0.5 degrees
        # 1 hr = 30 degrees
        # 3 hrs = 90 degrees

        hrDegree = (hour % 12) * 30 + (minutes * 0.5)
        minDegree = (6 * minutes)

        ans1 = 0
        ans2 = 0
        
        if minDegree > hrDegree:
            ans1 = minDegree - hrDegree
            ans2 = (360 - minDegree) + hrDegree
        elif minDegree < hrDegree:
            ans1 = hrDegree - minDegree
            ans2 = (360-hrDegree) + minDegree
        else:
            return 0
        return min(ans1,ans2)
        
