class Solution:
    def isValid(self, s: str) -> bool:
        pair = {
            "(": ")",
            "{": "}",
            "[": "]"
        }
        stack = []
        for c in s:
            if c == "(" or c == "{" or c == "[":
                stack.append(c)
            else:
                if not stack or c != pair[stack.pop()]:
                    return False
        if stack:
            return False
        return True
