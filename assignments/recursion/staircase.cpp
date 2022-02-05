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
	cout << "n = 1:" << stepPerms(1) << endl;
	cout << "n = 2:" << stepPerms(2) << endl;
	cout << "n = 3:" << stepPerms(3) << endl;
	cout << "n = 4:" << stepPerms(4) << endl;
	cout << "n = 5:" << stepPerms(5) << endl;
	cout << "n = 6:" << stepPerms(6) << endl;	
	cout << "n = 7:" << stepPerms(7) << endl;
}
