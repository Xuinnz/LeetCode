class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        arr = []
        count = 0
        for c in s:
            if c == "(":
                count += 1
                arr.append(count)
            else:
                arr.append(count)
                count -= 1
        outermost = min(arr)
        ans = ""
        for i in range(len(s)):
            if arr[i] == outermost:
                continue
            ans += s[i]
        return ans
