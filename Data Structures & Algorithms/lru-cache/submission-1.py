class Node:
    def __init__(self, key=0, val=0, left=None, right=None):
        self.key = key
        self.val = val
        self.left = left
        self.right = right

class LRUCache:
    def __init__(self, capacity: int):
        self.data = {}
        self.newest = None
        self.oldest = None
        self.length = 0
        self.capacity = capacity

    def get(self, key: int) -> int:
        if (key not in self.data):
            return -1
        if (self.data[key] is self.newest):
            return self.data[key].val
        elif (self.data[key] is self.oldest):
            self.oldest = self.oldest.left
            self.oldest.right = None

            self.data[key].right = self.newest
            self.newest.left = self.data[key]
            self.data[key].left = None
            self.newest = self.data[key]

            return self.data[key].val
        else:
            self.data[key].left.right = self.data[key].right
            self.data[key].right.left = self.data[key].left
            self.data[key].left = None
            self.data[key].right = self.newest
            self.newest.left = self.data[key]
            self.newest = self.data[key]
            return self.data[key].val

    def put(self, key: int, value: int) -> None:
        if (key in self.data):
            if self.data[key] is self.newest:
                self.data[key].val = value
                return
            elif self.data[key] is self.oldest:
                self.oldest = self.data[key].left
                self.oldest.right = None

                self.newest.left = self.data[key]
                self.data[key].right = self.newest
                self.newest =  self.data[key]
                self.data[key].val = value
            else:
                leftNode = self.data[key].left
                rightNode = self.data[key].right
                leftNode.right = rightNode
                rightNode.left = leftNode
                self.data[key].left = None
                self.data[key].right = self.newest
                self.data[key].val = value
                self.newest.left = self.data[key]
                self.newest = self.data[key]
            return

        if (self.length < self.capacity):
            if self.length == 0:
                newNode = Node(key=key, val=value, left=None, right=None)
                self.newest = newNode
                self.oldest = newNode
                self.data[key] = newNode
                self.length += 1
            else:
                newNode = Node(key=key, val=value, left=None, right=self.newest)
                self.newest.left = newNode
                self.newest = newNode
                self.data[key] = newNode
                self.length += 1
        else:
            newNode = Node(key=key, val=value, left=None, right=self.newest)
            self.newest.left = newNode
            self.newest = newNode
            self.data[key] = newNode
            oldestKey = self.oldest.key
            self.oldest = self.oldest.left 
            self.oldest.right = None
            del self.data[oldestKey]

            
        
