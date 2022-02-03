#include <iostream>
using namespace std;

int stepPerms(int n) {
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else if(n==3)
		return 4;
	else
		return (stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3));
}

int main() {
	cout << "n = 1:" << stepPerms(1) << endl;
	cout << "n = 3:" << stepPerms(3) << endl;
	cout << "n = 5:" << stepPerms(5) << endl;	
	cout << "n = 7:" << stepPerms(7) << endl;
}
