class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        isSigned = False
        isDecimal = False
        isExponent = False
        for index, char in enumerate(s):
            # no alphabets other than e
            if char not in "eE1234567890-+.":
                return False
            #SIGN RULES
            if char in "+-":
                if index + 1 == n:
                    return False
                if index == 0 and isSigned == False:
                    isDecimal == True
                    continue
                # optional signs if index - 1 is e
                elif s[index - 1] in 'eE':
                    continue
                #if multiple signs, false
                elif isSigned == True:
                    return False
                #No sign not in start
                elif index > 0 and isSigned == False:
                    return False
            #DECIMAL RULES
            if char == '.':
                if n == 1:
                    return False
                left_digit = index > 0 and s[index-1].isdigit()
                right_digit = index + 1 < n and s[index+1].isdigit()
                if not left_digit and not right_digit:
                    return False
                elif isDecimal == False and isExponent == False:
                    isDecimal = True
                    continue
                #no multiple .
                else: return False
            #exponent
            if char in 'Ee':
                if index == 0:
                    return False
                elif s[index - 1] in "+-":
                    return False
                elif index + 1 == n:
                    return False
                elif isExponent == False:
                    isExponent = True
                    continue
                else: return False
            if char.isdigit():
                continue
        return True