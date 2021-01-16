import util

def selection_sort(a, length):
    n = length
    i = 0

    while i < n:
        min = i
        j = i + 1
        while j < n:
            if (util.less(a[j], a[min])):
                min = j
            j += 1
        util.exchange(a, i, min)
        i += 1
