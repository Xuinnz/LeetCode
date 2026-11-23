class ProductOfNumbers:

    def __init__(self):
        self.arr = []

    def add(self, num: int) -> None:
        if num == 0:
            self.arr = [0] * len(self.arr)
            self.arr.append(num)
            return
        if num == 1:
            self.arr.append(num)
            return
        for i in range(len(self.arr)):
            self.arr[i] *= num
        self.arr.append(num)

    def getProduct(self, k: int) -> int:
        return self.arr[len(self.arr) - k]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
