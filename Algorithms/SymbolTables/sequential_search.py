from symbol_table import SymbolTable
from array import array

class SequentialSearch(SymbolTable):
    def __init__(self):
        self.__first = None
        self.__n = 0

    class Node:
        def __init__(self, key: int, val: str, next):
            self.key = key
            self.val = val
            self.next = next

    def get(self, key: int):
        x = self.__first
        while x != None:
            if key == x.key: return x.val
            x = x.next
        return None

    def put(self, key: int, val: str):
        x = self.__first
        while x != None:
            if key == x.key: x.val = val
            x = x.next
        self.__first = self.Node(key, val, self.__first)
        self.__n += 1

    def keys(self):
        keys = array('i')
        x = self.__first
        while x != None:
            keys.append(x.key)
            x = x.next
        return keys

    def delete(self, key):
        x = self.__first
        while x != None:
            if key == x.key:
                x.val = None
                self.__n -= 1
            x = x.next
        return None

    def size(self): return self.__n


def main():
    st = SequentialSearch()
    st.put(25, "Owen")
    print(st.get(25))

if __name__ == "__main__": main()