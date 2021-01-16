import util
from array import array

aux = array('i', [])

def merge_sort(a, length):
    # fill up aux array
    temp = 0
    while temp != length:
        aux.append(a[temp])
        temp += 1
    sort(a, 0, length - 1)

def sort(a, lo, hi):
    if hi <= lo: return
    mid = lo + int((hi - lo) / 2)
    sort(a, lo, mid)
    sort(a, mid + 1, hi)
    merge(a, lo, mid, hi)

def merge(a, lo, mid, hi):
    i = lo
    j = mid + 1
    k = lo
    while k <= hi:
        aux[k] = a[k]
        k += 1
    k = lo
    while k <= hi:
        if i > mid:
            a[k] = aux[j]
            j += 1
        elif j > hi:
            a[k] = aux[i]
            i += 1
        elif util.less(aux[j], aux[i]):
            a[k] = aux[j]
            j += 1
        else:
            a[k] = aux[i]
            i += 1
        k += 1

        