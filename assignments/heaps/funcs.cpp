#include <iostream>
#include "funcs.h"

void heapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1; //left child
	int r = 2 * i + 2; //right child
	if(l < n && arr[l] > arr[largest]) { //compare the parent with the left child
		largest = l; //If the left is child is bigger, set the index to the left child
	}
	if(r < n && arr[r] > arr[largest]) { //compare the parent with the right child 
		largest = r;//If the right is child is bigger, set the index to the right child
	}
	if(largest != i) { //if there is a bigger number
		std::swap(arr[i], arr[largest]); //swap the largest child with its parent 
		heapify(arr, n, largest); //heapify the lower subtree
	}
}

void heapSort(int arr[], int n) {
	for(int i = n/2 - 1; i >= 0; i--) { //build the maxheap from the bottom to the top
		heapify(arr, n, i);
	}
	for(int i = n - 1; i > 0; i--){
		std::swap(arr[0], arr[i]); //remove the biggest number and put it at the end of the array
		heapify(arr, i, 0); //build the maxheap and reduce the size by 1
	}
}

std::string print(int arr[], int size) {
	std::string r;
	for(int i = 0; i < size; i++) {
		r += std::to_string(arr[i]) + " ";
	}
	return r;
}
