from symbol_table import SymbolTable
from array import array

class BinarySearch(SymbolTable):
    def __init__(self, capacity):
        self.__keys = []
        self.__vals = []
        while capacity > 0:
            self.__keys.append(-1)
            self.__vals.append(-1)
            capacity -= 1
        self.__n = 0

    def size(self): return self.__n

    def get(self, key: int):
        if self.isEmpty(): return None
        i: int = self.rank(key)
        if i < self.__n and self.__keys[i] == key: return self.__vals[i]
        else: return None
    
    def rank(self, key: int):
        lo: int = 0
        hi: int = self.__n - 1
        while lo <= hi:
            mid: int = lo + int((hi - lo) / 2)
            if self.__keys[mid] > key: hi = mid - 1
            elif self.__keys[mid] < key: lo = mid + 1
            else: return mid
        return lo

    def put(self, key: int, val: int):
        i = self.rank(key)
        if i < self.__n and self.__keys[i] == key:
            self.__vals[i] = val
            return
        j = self.__n
        while j > i:
            self.__keys[j] = self.__keys[j-1]
            self.__vals[j] = self.__vals[j-1]
            j -= 1
        self.__keys[i] = key
        self.__vals[i] = val
        self.__n += 1

    def keys(self): return self.__keys
    def delete(self, key: int): 
        super().delete(key)
        self.__n -= 1
