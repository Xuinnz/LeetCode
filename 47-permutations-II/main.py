from typing import List

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [[nums[0]]]
        nums.sort()
        resArr = []
        def backtrack(currNums, arr):
            if not currNums:
                resArr.append(list(arr))
                return
            for i in range(len(currNums)):
                if i > 0 and currNums[i] == currNums[i - 1]:
                    continue
                arr.append(currNums[i])
                remaining = currNums[:i] + currNums[i + 1:]
                backtrack(remaining, arr)
                arr.pop()
        backtrack(nums, [])   
        return resArr  

# --- Main Function ---
def main():
    sol = Solution()
    
    # Test Case 1: Duplicates
    test_1 = [1, 1, 2]
    print(f"Input: {test_1}")
    result_1 = sol.permuteUnique(test_1)
    print(f"Unique Permutations: {result_1}")
    print(f"Count: {len(result_1)}")
    
    print("-" * 20)
    
    # Test Case 2: All same
    test_2 = [1, 1, 1]
    print(f"Input: {test_2}")
    result_2 = sol.permuteUnique(test_2)
    print(f"Unique Permutations: {result_2}")
    
    print("-" * 20)

    # Test Case 3: Mixed unique
    test_3 = [1, 2, 3]
    print(f"Input: {test_3}")
    result_3 = sol.permuteUnique(test_3)
    print(f"Unique Permutations: {result_3}")

if __name__ == "__main__":
    main()