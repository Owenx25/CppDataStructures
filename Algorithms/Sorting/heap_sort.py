import util
from array import array
from priority_queue import MaxPQ

def heap_sort(a, length):
    pq = MaxPQ(0)
    a.insert(0, -1)
    pq.sort_with_arr(a, length)

def main():
    a = array('i',[1,3,6,2,8,4,7,9,5])
    heap_sort(a, 9)
    util.print_arr(a)

if __name__ == "__main__": main()
