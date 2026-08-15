class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 1:
            return s
        mid = ""
        if n % 2 == 1:
            mid += s[n // 2]
        sorted_half = "".join(sorted(s[: n // 2]))

        reversed_half = "".join(reversed(sorted_half))

        return sorted_half + mid + reversed_half
