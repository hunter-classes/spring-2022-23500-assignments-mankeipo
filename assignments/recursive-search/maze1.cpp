#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

char me = 'Z';
char wall = ' ';
char goal = '$';
char path = '#';
char visited = '.';

int load_maze(string filename, string *maze) {
	ifstream infile(filename);
	int i = 0;
	while(getline(infile,maze[i])) {
		i++;
	}
	return i;
}

void print_maze(string maze[], int lines){
	cout << "[0;0H\n";
	for(int i = 0; i < lines; i++) {
		cout << maze[i] << "\n";
	}
}

void solve(string maze[], int lines, int row, int col, bool &solved){
	if(maze[row][col] == wall || maze[row][col] == me) {
		return;
	}
	maze[row][col] = me;
	//usleep(80000);
	print_maze(maze, lines);
	if(!solved) solve(maze, lines, row - 1, col + 2, solved);
    if(!solved) solve(maze, lines, row + 1, col + 2, solved);
    if(!solved) solve(maze, lines, row + 1, col - 2, solved);
    if(!solved) solve(maze, lines, row - 1, col - 2, solved);
    if(!solved) solve(maze, lines, row - 2, col + 1, solved);
    if(!solved) solve(maze, lines, row - 2, col - 1, solved);
    if(!solved) solve(maze, lines, row + 2, col - 1, solved); 
    if(!solved) solve(maze, lines, row + 2, col + 1, solved);
	if (!solved) maze[row][col] = path;
}

int main() {
	string maze[10];
	int lines;
	lines = load_maze("maze1.dat", maze);
	cout << "[2J;\n";
	print_maze(maze,lines);
	bool solved = false;
	solve(maze,lines,2,2,solved);
	return 0;
}
