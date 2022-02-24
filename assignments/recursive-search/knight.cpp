#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <iomanip> 
using namespace std;

void solve(int array[][5], int row, int col, int moveCount, bool &solved) {
	if(moveCount > 25) {
		solved = true;
		return;
	}
	if(row < 0 || row >= 5 || col < 0 || col >= 5 || array[row][col] > 0) {
		return;
	}
	array[row][col] = moveCount;
	moveCount++;

	if (!solved) solve(array, row-1,col+2,moveCount,solved);
  	if (!solved) solve(array, row-2,col+1,moveCount,solved);
  	if (!solved) solve(array, row+1,col+2,moveCount,solved); 
  	if (!solved) solve(array, row-2,col-1,moveCount,solved); 
  	if (!solved) solve(array, row+2,col+1,moveCount,solved); 
  	if (!solved) solve(array, row+2,col-1,moveCount,solved);
  	if (!solved) solve(array, row-1,col-2,moveCount,solved);
	if (!solved) solve(array, row+1,col-2,moveCount,solved);
	if (!solved){
		array[row][col] = 0;
		moveCount--;
	}
}
	
int main() {
	int arr[5][5];
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			arr[i][j] = 0;
		}
	}
	
	bool solved = false;
	solve(arr, 0, 0, 1, solved);
	arr[0][0] = 1;
	if(solved) {
	for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                        cout << setw(3) << arr[i][j];
                }
		cout << endl;
        }
	}
}
