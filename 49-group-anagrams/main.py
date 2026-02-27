from collections import Counter
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}

        for i, n in enumerate(strs):
            sort = tuple(sorted(n))
            if sort not in hashmap:
                hashmap[sort] = []
                hashmap[sort].append(n)
            else:
                hashmap[sort].append(n)
        return list(hashmap.values())
