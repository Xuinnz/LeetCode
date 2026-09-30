class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        arr = []
        arr.append(0)
        count = 0
        for i in range(1, len(seq)):
            if seq[i] == "(" and seq[i] == seq[i - 1]:
                count += 1
                arr.append(count)
                continue
            elif seq[i] == ")" and seq[i] == seq[i - 1]:
                count -= 1
                arr.append(count)
                continue
            arr.append(count)
        mean = max(arr) // 2

        for i in range(len(arr)):
            if mean >= arr[i]:
                arr[i] = 1
            else:
                arr[i] = 0
        return arr
