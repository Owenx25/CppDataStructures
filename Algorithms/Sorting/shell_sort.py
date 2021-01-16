import util

def shell_sort(a, length):
    n = length
    h = 1
    while h < n/3:
        h = 3 * h + 1
    while h >= 1:
        i = h
        while i < n:
            j = i
            while j >= h and util.less(a[j], a[j-h]): 
                util.exchange(a, j, j-h)
                j -= h
            i += 1
        h = int(h / 3)