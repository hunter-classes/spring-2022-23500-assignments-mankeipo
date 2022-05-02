#include <iostream>
using namespace std;

int arr[10000];
int stepPerms(int n) {
	if(n < 2) {
		return 1;
	} else if(arr[n] != 0) {
		return arr[n];
	} else {
		int temp = stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
		arr[n] = temp;
		return temp;
	}  	
}

int main() {
	for(int i = 0; i < 10000; i++) {
		arr[i] = 0;
	}
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for(int i = 0; i < 200; i++) {
		cout << "n = " << i << ":" << stepPerms(i) << endl;
	}
}
