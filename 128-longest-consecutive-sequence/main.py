def longestConsecutive(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if not nums:
       return 0
    hash_set = set(nums)
    maxCount = 1
    for num in hash_set:
        j = 1
        count = 1
        if (num - 1) in hash_set:
            continue
        while num + j in hash_set:
            count += 1
            j += 1
        if count > maxCount:
            maxCount = count
    return maxCount


if __name__ == "__main__":
    # Test Cases
    test_cases = [
        ([100, 4, 200, 1, 3, 2], 4, "Normal case: 1,2,3,4"),
        ([0, 3, 7, 2, 5, 8, 4, 6, 0, 1], 9, "Large sequence: 0-8"),
        ([], 0, "Empty list"),
        ([1, 2, 0, 1], 3, "Duplicates in list"),
        ([10, 5, 12, 3], 1, "No consecutive numbers")
    ]

    print(f"{'Description':<30} | {'Input':<35} | {'Result':<10} | {'Status'}")
    print("-" * 95)

    for nums, expected, desc in test_cases:
        result = longestConsecutive(nums)
        status = "✅" if result == expected else "❌"
        print(f"{desc:<30} | {str(nums):<35} | {result:<10} | {status}")