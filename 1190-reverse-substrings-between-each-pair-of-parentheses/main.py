class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        arr = []
        i = 0 
        filtered = ""
        for c in s:
            if c == "(":
                stack.append(i)
                continue
            if c == ")":
                arr.append([stack.pop(), i])
                continue
            filtered += c
            i += 1
        
        for a in arr:
            filtered = filtered[:a[0]] + filtered[a[0]:a[1]][::-1] + filtered[a[1]:]
        return filtered
