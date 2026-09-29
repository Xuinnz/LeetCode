class Node:
    def __init__(self, key=0, val=0):
        self.key = 0
        self.val = 0
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.len = 0
        self.keyval = {}

        self.head = Node()
        self.tail = Node()

        self.head.next = self.tail
        self.tail.prev = self.head

    def get(self, key: int) -> int:
        if key not in self.keyval: return -1
        node = self.keyval[key]
        node.prev.next = node.next
        node.next.prev = node.prev
        temp = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = temp
        temp.prev = node
        return node.val

    def put(self, key: int, value: int) -> None:
        # check if the key exist first. if yes, we update it
        if key in self.keyval:
            node = self.keyval[key]
            node.val = value
            node.prev.next = node.next
            node.next.prev = node.prev
            temp = self.head.next
            self.head.next = node
            node.prev = self.head
            node.next = temp
            temp.prev = node
            return
        self.len += 1
        if self.len > self.capacity:
            del self.keyval[self.tail.prev.key]
            self.tail.prev.prev.next = self.tail
            self.tail.prev = self.tail.prev.prev

        # Initialize the node, key, val
        entry = Node()
        entry.key = key
        entry.val = value
        # put into the dict
        self.keyval[key] = entry
        # get the current head and put it into a temp
        temp = self.head.next
        # rewrite the head use the entry, and connect back
        self.head.next = entry
        entry.prev = self.head
        # connect the prev head to the new head and connect back
        entry.next = temp
        temp.prev = entry


        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
