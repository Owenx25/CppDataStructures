from array import array
import util

class MaxPQ:
    def __init__(self, maxN):
        self.__n = 0
        self.__pq = array('i', [])
        while maxN + 1 > 0:
            self.__pq.append(-1)
            maxN -= 1

    def sort_with_arr(self, a, length):
        self.__pq = a
        self.__n = length
        k = int(self.__n/2)
        while k >= 1:
            self.__sink(k)
            k -= 1
        while self.__n > 1:
            self.__exch(1, self.__n)
            self.__n -= 1
            self.__sink(1)
        self.__pq.pop(0)

    def is_empty(self): return self.__n == 0

    def size(self): return self.__n

    def insert(self, v):
        self.__n += 1
        self.__pq[self.__n] = v
        self.__swim(self.__n)

    def delMax(self):
        max = self.__pq[1]
        self.__exch(1, self.__n)
        self.__n -= 1
        self.__pq[self.__n + 1] = -1
        self.__sink(1)
        return max

    def __exch(self, i, j):
        t = self.__pq[i]
        self.__pq[i] = self.__pq[j]
        self.__pq[j] = t

    def __less(self, i, j): return self.__pq[i] < self.__pq[j] 

    def __swim(self, k):
        while k > 1 and self.__less(int(k/2), k):
            self.__exch(int(k/2), k)
            k = int(k/2)

    def __sink(self, k):
        while 2 * k <= self.__n:
            j = 2 * k
            if j < self.__n and self.__less(j, j + 1): j += 1
            if not self.__less(k, j): break
            self.__exch(k, j)
            k = j

    def print(self):
        util.print_arr(self.__pq)
        print("n is " + str(self.__n))

def main():
    pq = MaxPQ(10)
    pq.insert(5)
    pq.insert(3)
    pq.insert(6)
    pq.insert(8)
    pq.insert(1)
    pq.delMax()
    pq.print()

if __name__ == "__main__": main()

