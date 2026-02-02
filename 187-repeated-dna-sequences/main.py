def findRepeatedDnaSequences(s: str):
    charCount = 10
    strlen = len(s)
    hash_map = {}
    for i in range(strlen - 9):
        substring = s[i: i + charCount]
        if substring not in hash_map:
            hash_map[substring] = 1
        else: 
            hash_map[substring] += 1
    ans = []
    for i, n in hash_map.items():
        if n > 1:
            ans.append(i)
    return ans

if __name__ == "__main__":
    # Test cases
    tests = [
        ("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", ["AAAAACCCCC", "CCCCCAAAAA"], "Standard Case"),
        ("AAAAAAAAAAAAA", ["AAAAAAAAAA"], "Highly Repetitive"),
        ("ABC", [], "String too short"),
        ("AAAAAAAAAAA", ["AAAAAAAAAA"], "Overlapping sequences"),
        ("", [], "Empty string")
    ]

    print(f"{'Description':<20} | {'Result':<30} | {'Status'}")
    print("-" * 65)

    for s, expected, desc in tests:
        result = findRepeatedDnaSequences(s)
        # Sort results to compare correctly regardless of order
        status = "✅" if sorted(result) == sorted(expected) else "❌"
        print(f"{desc:<20} | {str(result):<30} | {status}")