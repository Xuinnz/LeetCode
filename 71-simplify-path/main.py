from collections import deque
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = deque()
        i = 0
        n = len(path)
        while i < n:
            while i < n and path[i] == '/':
                i += 1
            if i > n: break
            fname = ""
            while i < n and path[i] != '/':
                fname += path[i]
                i += 1
            if fname == '.':
                continue
            elif fname == '..':
                if stack: stack.pop()
            else:
                if len(fname) > 0:w
                    stack.append(fname)
        
        output = ""
        if not stack:
            return "/"
        for i, n in enumerate(stack):
            output += '/' + n
        return output
            
