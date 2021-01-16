from symbol_table import SymbolTable

class Color:
    RED = 1
    BLACK = 2

class RBT(SymbolTable):
    def __init__(self):
        self.__root = None

    class Node:
        def __init__(self, key: int, val: str, n: int, color: Color):
            self.key = key
            self.val = val
            self.left = None
            self.right = None
            self.n = n
            self.color = color

    def rotateLeft(self, h: Node):
        x = h.right
        h.right = x.left
        x.left = h
        x.color = h.color
        h.color = Color.RED
        x.n = h.n
        h.n = 1 + self.__sub_size(h.left) + self.__sub_size(h.right)
        return x

    def rotateRight(self, h: Node):
        x: self.Node = h.left
        h.left = x.right
        x.right = h
        x.color = h.color
        h.color = Color.RED
        x.n = h.n
        h.n = 1 + self.__sub_size(h.left) + self.__sub_size(h.right)
        return x

    def flipColors(self, h: Node):
        h.color = Color.RED
        h.left.color = Color.BLACK
        h.right.color = Color.BLACK

    def isRed(self, x: Node):
        if x is None: return False
        return x.color == Color.RED

    def size(self):
        return self.__sub_size(self.__root)
        
    def __sub_size(self, x: Node):
        if x is None: return 0
        else: return x.n

    def get(self, key: int):
        return self.__sub_get(self.__root, key)

    def __sub_get(self, x, key: int):
        if x is None: return None
        if key < x.key: return self.__sub_get(x.left, key)
        elif key > x.key: return self.__sub_get(x.right, key)
        else: return x.val

    def put(self, key: int, val: str):
        self.__root = self.__sub_put(self.__root, key, val)
        self.__root.color = Color.BLACK

    def __sub_put(self, x: Node, key: int, val: str):
        if x is None: return self.Node(key, val, 1, Color.RED)
        if key < x.key: x.left = self.__sub_put(x.left, key, val)
        elif key > x.key: x.right = self.__sub_put(x.right, key, val)
        else: x.val = val

        if self.isRed(x.right) and not self.isRed(x.left): x = self.rotateLeft(x)
        if self.isRed(x.left) and self.isRed(x.left.left): x = self.rotateRight(x)
        if self.isRed(x.left) and self.isRed(x.right): self.flipColors(x)

        x.n = self.__sub_size(x.left) + self.__sub_size(x.right) + 1
        return x

    def keys(self):
        return self.__sub_keys(self.__root)

    def __sub_keys(self, x):
        if x is None: return []
        return self.__sub_keys(x.left) + self.__sub_keys(x.right) + [x.key]

    def deleteMin(self):
        if self.isEmpty(): raise IndexError
        root = self.__sub_deleteMin(self.__root)

    def __sub_deleteMin(self, x):
        if x.left is None: return x.right
        x.left = self.__sub_deleteMin(x.left)
        x.n = self.__sub_size(x.left) + self.__sub_size(x.right) + 1
        return x

    def delete(self, key):
        self.__root = self.__sub_delete(self.__root, key)

    def __sub_delete(self, x, key):
        if x is None: return None
        if key < x.key: x.left = self.__sub_delete(x.left, key)
        elif key > x.key: x.right = self.__sub_delete(x.right, key)
        else:
            if x.right is None: return x.left
            if x.left is None: return x.right
            t = x
            x = self.__sub_min(t.right)
            x.right = self.__sub_deleteMin(t.right)
            x.left = t.left
        x.n = self.__sub_size(x.left) + self.__sub_size(x.right) + 1
        return x

    def min(self):
        if self.isEmpty(): raise IndexError
        return self.__sub_min(self.__root)

    def __sub_min(self, x):
        if x.left is None: return x
        return self.__sub_min(x.left)

