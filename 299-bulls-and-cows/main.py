class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A = 0
        B = 0
        arr = []
        hmap = {}
        for i, n in enumerate(secret):
            if n not in hmap:
                hmap[n] = 1
            else:
                hmap[n] += 1
        for i, n in enumerate(guess):
            if n == secret[i]:
                arr.append(1)
                hmap[n] -= 1
        for i, n in enumerate(guess):
            if n == secret[i]:
                continue
            elif n in hmap and hmap[n] > 0:
                arr.append(0)
                hmap[n] -= 1 
        for i in range(len(arr)):
            if arr[i] == 1:
                A += 1
            elif arr[i] == 0:
                B += 1
        return f"{A}A{B}B"