class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        hashmap = {}
        for k in knowledge:
            hashmap[k[0]] = k[1]
        
        i = 0
        ans = ""
        parse = False
        parseData = ""
        while i < len(s):
            if s[i] == "(":
                parse = True
                i += 1
                continue
            elif s[i] == ")":
                parse = False
                if parseData in hashmap:
                    ans += hashmap[parseData]
                else:
                    ans += "?"
                parseData = ""
                i += 1
                continue
            if parse:
                parseData += s[i]
                i += 1
                continue
            ans += s[i]
            i += 1
        return ans
