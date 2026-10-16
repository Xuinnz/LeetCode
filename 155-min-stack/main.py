class Node:
    def __init__(self):
        self.val = 0
        self.min = None
        self.next = None
        self.prev = None

class MinStack:

    def __init__(self):
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
    
    def push(self, value: int) -> None:
        temp = self.tail.prev
        entry = Node()
        entry.val = value
        entry.min = value
        temp.next = entry
        entry.prev = temp
        entry.next = self.tail
        self.tail.prev = entry

        if temp.min is not None and temp.min < entry.min:
            entry.min = temp.min
        
    def pop(self) -> None:
        temp = self.tail.prev.prev
        ans = self.tail.prev
        temp.next = self.tail
        self.tail.prev = temp

    def top(self) -> int:
        return self.tail.prev.val

    def getMin(self) -> int:
        return self.tail.prev.min


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
