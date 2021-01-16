from random import randint
from array import array

def less(a, b):
    return a < b

def exchange(a, first, second):
    temp = a[first]
    a[first] = a[second]
    a[second] = temp

def print_arr(a):
    print('[ ', end='')
    for element in a:
        print(str(element), end=' ')
    print(']')

def gen_random_arr(size):
    arr = array('i', [])
    while size > 0:
        arr.append(randint(0, 99999))
        size -= 1
    return arr
