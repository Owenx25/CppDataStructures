import util

def insertion_sort(a, length):
    n = length
    i = 1

    while i < n:
        j = i
        while j > 0 and util.less(a[j], a[j - 1]):
            util.exchange(a, j, j - 1)
            j -= 1
        i += 1