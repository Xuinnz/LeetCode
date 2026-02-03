import random
class RandomizedSet:

    def __init__(self):
        self.hash_map = {}
        self.count = 0
        self.myList = []

    def insert(self, val: int) -> bool:
        if val in self.hash_map:
            return False
        self.hash_map[val] = self.count
        self.myList.append(val)
        self.count += 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.hash_map:
            return False
        idx = self.hash_map[val]
        lastVal = self.myList[-1]

        self.myList[idx] = lastVal
        self.hash_map[lastVal] = idx

        self.myList.pop()
        del self.hash_map[val]
        self.count -= 1
        return True

    def getRandom(self) -> int:
        return random.choice(self.myList)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()