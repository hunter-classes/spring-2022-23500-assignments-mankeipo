#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("heapSort"){
        int arr1[] = {-100, 4, 2, 5, 1, 3};
        int arr2[] = {12, 11, 13, 5, 6, 7};
        int arr3[] = {80, 9 , 700, 40, 1, 5, 200};
        heapSort(arr1, 6);
        heapSort(arr2, 6);
        heapSort(arr3, 6);
        CHECK(print(arr1, 6) == "-100 1 2 3 4 5 ");
        CHECK(print(arr2, 6) == "5 6 7 11 12 13 ");
        CHECK(print(arr3, 6) == "1 5 9 40 80 700 ");
}
