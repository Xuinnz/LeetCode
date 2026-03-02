class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = list(range(1, n + 1))
        k -= 1
        permutation = ""

        for i in range(n, 0, -1):
            size = math.factorial(i - 1)
            #get the size
            index = k // size
            #get the block
            permutation += str(nums.pop(index))
            #put the index
            k = k % size
            #get the remainder
        return permutation




        
