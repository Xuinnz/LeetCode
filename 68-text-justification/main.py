class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        outputArr = []
        i = 0
        while i < len(words):
            currentLen = 0
            lineArr = [] 
            while i < len(words) and currentLen + len(words[i]) + len(lineArr) <= maxWidth:
                currentLen += len(words[i])
                lineArr.append(words[i])
                i += 1

            lineWords = len(lineArr)
            gaps = lineWords - 1
            padding = maxWidth - currentLen
            if lineWords == 1 or i == len(words):
                lineStr = " ".join(lineArr)
                lineStr += " " * (maxWidth - len(lineStr))
                
            else:
                space = padding // gaps
                extraSpace = padding % gaps

                lineStr = ""

                for j in range(gaps):
                    lineStr += lineArr[j]
                    lineStr += " " * (space + (1 if j < extraSpace else 0))
                lineStr += lineArr[-1]
            outputArr.append(lineStr)
        return outputArr
                

            

