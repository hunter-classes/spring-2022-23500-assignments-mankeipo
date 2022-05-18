#include <iostream>
#include "funcs.h"

int main() {
	int arr[6] = {12, 11, 13, 5, 6, 7};
	heapSort(arr,6);
	std::cout << print(arr, 6);	
}
