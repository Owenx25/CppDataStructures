# Symbol Table for storing values associated with a particular key.

class SymbolTable:
    def __init__(self):
        pass

    def put(self, key: int, value: str): raise NotImplementedError
    def get(self, key: int): raise NotImplementedError
    def delete(self, key: int): self.put(key, None)
    def contains(self, key: int): return self.get(key) != None
    def isEmpty(self): return self.size() == 0
    def size(self): raise NotImplementedError
    def keys(self): raise NotImplementedError

    # def min(self): raise NotImplementedError
    # def max(self): raise NotImplementedError
    # def floor(self, key: int): raise NotImplementedError
    # def ceiling(self, key: int): raise NotImplementedError
    # def rank(self, key: int): raise NotImplementedError
    # def select(self, k: int): raise NotImplementedError

    # def deleteMin(self): self.delete(min())
    # def deleteMax(self): self.delete(max())
    # def size(self, lo: int=0, hi: int=-1):
    #     if hi < 0: return 0
    #     elif self.contains(hi):
    #         return self.rank(hi) - self.rank(lo) + 1
    #     else: return self.rank(hi) - self.rank(lo)
    # def keys(self, lo: int=0, hi: int=-1): raise NotImplementedError

    
