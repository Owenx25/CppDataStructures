import util
from random import shuffle

def quick_sort(a, length):
    shuffle(a)
    sort(a, 0, length - 1)

def sort(a, lo, hi):
    if hi <= lo: return
    j = partition(a, lo, hi)
    sort(a, lo, j - 1)
    sort(a, j + 1, hi)

def partition(a, lo, hi):
    i = lo
    j = hi + 1
    v = a[lo]

    while True:
        i += 1
        while util.less(a[i], v): 
            if i == hi: break
            i += 1
        j -= 1
        while util.less(v, a[j]): 
            if j == lo: break
            j -= 1
        if i >= j: break
        util.exchange(a, i, j)
    util.exchange(a, lo, j)
    return j