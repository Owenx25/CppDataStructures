from symbol_table import SymbolTable

class BST(SymbolTable):
    def __init__(self):
        self.__root = None

    class Node:
        def __init__(self, key: int, val: str, n: int):
            self.key = key
            self.val = val
            self.left = None
            self.right = None
            self.n = n

    def size(self):
        return self.__sub_size(self.__root)
        
    def __sub_size(self, x):
        if x is None: return 0
        else: return x.n

    def get(self, key: int):
        return self.__sub_get(self.__root, key)

    def __sub_get(self, x, key: int):
        if x is None: return None
        if key < x.key: return self.__sub_get(x.left, key)
        elif key > x.key: return self.__sub_get(x.right, key)
        else: return x.val

    def put(self, key: int, val: int):
        self.__root = self.__sub_put(self.__root, key, val)

    def __sub_put(self, x, key: int, val: int):
        if x is None: return self.Node(key, val, 1)
        if key < x.key: x.left = self.__sub_put(x.left, key, val)
        elif key > x.key: x.right = self.__sub_put(x.right, key, val)
        else: x.val = val
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

