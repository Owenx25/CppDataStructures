import unittest
import util
import time
from array import array
from selection_sort import selection_sort
from insertion_sort import insertion_sort
from shell_sort import shell_sort
from merge_sort import merge_sort
from quick_sort import quick_sort
from heap_sort import heap_sort

class TestSort(unittest.TestCase):
    def setUp(self):
        self.startTime = time.time()

    def tearDown(self):
        t = time.time() - self.startTime
        print('%s: %.7f' % (self.id(), t))
        print('')

    def test_short(self):
        arr = array('i', [5, 7, 6, 2, 1, 9, 0, 3, 4])
        sort_and_print(arr, 9)
        self.assertEqual(arr, array('i', [0, 1, 2, 3, 4, 5, 6, 7, 9]))

    def test_empty(self):
        arr = array('i', [])
        sort_and_print(arr, 0)
        self.assertEqual(arr, array('i', []))

    def test_short_duplicates(self):
        arr = array('i', [5, 7, 5, 2, 1, 9, 0, 3, 4])
        sort_and_print(arr, 9)
        self.assertEqual(arr, array('i', [0, 1, 2, 3, 4, 5, 5, 7, 9]))

    def test_all_duplicates(self):
        arr = array('i', [])
        dup_count = 2000
        while dup_count > 0: 
            arr.append(7) # It's REAL lucky
            dup_count -= 1
        sort_and_print(arr, 200)
        self.assertEqual(arr, arr)
    
    def test_long(self):
        arr = util.gen_random_arr(500)
        sort_and_print(arr, 500)

    def test_loooooong(self):
        arr = util.gen_random_arr(10000)
        sort_and_print(arr, 10000)

def sort_and_print(arr, length):
    print('Before: ')
    util.print_arr(arr)

    # SORTING ALGORITHM
    #selection_sort(arr, length)
    #insertion_sort(arr, length)
    #shell_sort(arr, length)
    #merge_sort(arr, length)
    quick_sort(arr, length)
    #heap_sort(arr, length)

    print('After: ')
    util.print_arr(arr)

if __name__ == '__main__':
    unittest.main()
