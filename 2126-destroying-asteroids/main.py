class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        mx = max(asteroids)
        asteroids.sort()

        for i, n in enumerate(asteroids):
            if mass >= n:
                mass += n
            else:
                return False
            if mass >= mx:
                return True
        return True

