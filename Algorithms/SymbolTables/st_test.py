import unittest
from sequential_search import SequentialSearch
from binary_search import BinarySearch
from binary_search_tree import BST
from red_black_tree import RBT

class TestSymbolTable(unittest.TestCase):
    def setUp(self):
        # Change this line to swap implementations
        #self.__st = SequentialSearch()
        #self.__st = BinarySearch(20)
        #self.__st = BST()
        self.__st = RBT()

    def test_get_where_put_single_key(self):
        self.__st.put(25, "Owen")
        actual = self.__st.get(25)

        self.assertIs(actual, "Owen")

    def test_get_where_put_multiple_keys(self):
        self.__st.put(25, "Owen")
        self.__st.put(31, "Juan")
        self.__st.put(27, "Stephen")
        self.__st.put(16, "Enrique")
        actual = self.__st.get(27)

        self.assertIs(actual, "Stephen")

    
    def test_get_after_insert_and_delete(self):
        self.__st.put(25, "Owen")
        self.__st.put(31, "Juan")
        self.__st.put(27, "Stephen")
        self.__st.put(16, "Enrique")
        self.__st.delete(25)
        actual = self.__st.get(25)

        self.assertIs(actual, None)


    def test_get_where_missing_key(self):
        actual = self.__st.get(25)
        self.assertIsNone(actual)

    def test_size_where_st_empty(self):
        actual = self.__st.size()
        self.assertIs(actual, 0)

    def test_size_after_put(self):
        self.__st.put(1, "uno")
        self.__st.put(2, "dos")
        self.__st.put(3, "tres")
        self.__st.put(4, "cuatro")
        actual = self.__st.size()

        self.assertIs(actual, 4)

    def test_size_after_put_and_delete(self):
        self.__st.put(1, "uno")
        self.__st.put(2, "dos")
        self.__st.put(3, "tres")
        self.__st.put(4, "cuatro")
        self.__st.delete(2)
        actual = self.__st.size()

        self.assertIs(actual, 3)
        
    def test_keys_after_put(self):
        self.__st.put(1, "One")
        self.__st.put(2, "Two")
        self.__st.put(3, "Three")
        self.__st.put(4, "Four")
        self.__st.put(5, "Five")

        actual = self.__st.keys()
        self.assertTrue(actual.count(1), 1)
        self.assertTrue(actual.count(2), 1)
        self.assertTrue(actual.count(3), 1)
        self.assertTrue(actual.count(4), 1)
        self.assertTrue(actual.count(5), 1)


if __name__ == '__main__':
    unittest.main()