#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

int count(std::vector<int> v, int value) {
	int count = 0;
	for(int i = 0; i < v.size(); i++) {
		if(v[i] == value) {
			count++;
		}
	}
	return count;
}

int largest(std::vector<int> v) {
	int max = INT_MIN;
	for(int i = 0; i < v.size(); i++) {
		if(v[i] > max) {
			max = v[i];
		}
	}
	return max;
}

int mode(std::vector<int> v) {
	int repeat = 0;
	int num;
	for(int i = 0; i < v.size(); i++) {
		if(count(v,v[i]) > repeat) {
			repeat = count(v,v[i]);
			num = v[i];
		}
	}
	return num;
}

int mode2(std::vector<int> v) {
	int max_val = 0;
	for (auto i : v) {
		if (i > max_val) {
			max_val = i;
		}
	}
	std::vector<int> counts (max_val+1);
	for (auto i : v) {
		counts[i]++;
	}
	int mode_index = 0;
	for(int i = 0; i < max_val+1; i++) {
		if(counts[i] > counts[mode_index]) {
			mode_index = i;
		}
	}
	return mode_index;
}
	
int main() {
	std::vector<int> vect = {4,4,4,4,4,4,4,4,12,12,12,12,12};
	std::cout << count(vect, 4) << std::endl;
	std::cout << largest(vect) << std::endl;
	std::vector<int> vect1 = {1,5,4,6,4,8,6,4,12,6,22};
	std::cout << mode(vect1) << std::endl;
	std::cout << mode2(vect1) << std::endl;	
}
