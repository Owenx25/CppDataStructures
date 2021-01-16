import sys

def exchange(a, first, second):
    temp = a[first]
    a[first] = a[second]
    a[second] = temp