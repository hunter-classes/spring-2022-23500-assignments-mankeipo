//credit to jubayer
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
	   int start_index,
	   int stop_index) {
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);

    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;

  }
  return a;
}

/*
  left and right are already sorted
  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here

  // remember merged.push_back(n)
  // appends value n to the vector merged

  int l = 0;
  int r = 0;

  while(l < left.size() && r < right.size()) {
    if(left[l] < right[r]) {
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  while(l < left.size()) {
    merged.push_back(left[l]);
    l++;
  }
  while(r < right.size()) {
    merged.push_back(right[r]);
    r++;
  }

  return merged;
}

std::vector<int> msort(std::vector<int> v) {
  if(v.size() < 2) {
    return v;
  }

  std::vector<int> v1;
  std::vector<int> v2;
  int size = v.size();

  for(int i = 0; i < size / 2; i++) {
    v1.push_back(v[i]);
  }

  for(int j =  size/2; j < size; j++) {
    v2.push_back(v[j]);
  }

  return merge(msort(v1), msort(v2));
}

std::vector<int> qsort (std::vector<int> list) {
	//base case
	if (list.size() <= 1) {
		return list;
	}

	//select a pivot value.
	//for now just pick list[0]
	int pivot = list[0];
	//make 2 new vectors
	std::vector<int> lower, higher;

	//copy all the values < pivot value to lower
	for(int i = 1; i < list.size(); i++) {
		if(list[i] < pivot) {
			lower.push_back(list[i]);
		} else {
			higher.push_back(list[i]);
		}
	}
	//copy all the values >= pivot value to higher

	lower = qsort(lower);
	higher = qsort(higher);

	//copy everything back into list
	list.clear();
	for(auto j: lower) {
		list.push_back(j);
	}

	list.push_back(pivot);

	for(auto k: higher) {
		list.push_back(k);
	}
	//return the sorted list

	return list;
}

void qsort2(std::vector<int>& list, int low, int high) {
  int pivotIndex = low + (high - low) / 2;
  int pivot = list[pivotIndex];
  int i = low, j = high;
  int temp;
  while(i <= j) {
      while(list[i] < pivot) {
          i++;
      }
      while(list[j] > pivot) {
          j--;
      }
      if(i <= j) {
          temp = list[i];
          list[i] = list[j];
          list[j] = temp;
          i++;
          j--;
      }
  }
  if(low < high) {
    qsort2(list, low, i - 1);
    qsort2(list, i, high);
  }
}

void print_help(char *command_name){
  std::cout << "Usage: "<< command_name;
  std::cout << " [-h|-p|-m N|-s N|-a algorithm]\n\n";
  std::cout << " -m MAX_ELEMENT_SIZE\n";
  std::cout << " -s DATA_SET_SIZE\n";
  std::cout << " -a[s|m]: s - selection, m - merge, q - quick, i - in-place\n";
}

extern char *optarg;

int main(int argc, char *argv[]) {
  int size = 20; // default vector size
  int max_val = 100; // default max value for entries

  char algorithm = 's' ; //default to selection sort
  bool print = false; // do we print before and after sorting?
  char c;


  while ( ( c = getopt(argc, argv, "phs:m:a:")) != -1) {

    switch (c) {
    case 'h' :
    	print_help(argv[0]);
    	exit(0);
    	break;
    case 'p' :
    	print = true;
    	break;
    case 's' :
    	size = std::stoi(optarg);
    	break;
    case 'm' :
    	max_val = std::stoi(optarg);
    	break;
    case 'a':
    	algorithm = optarg[0]; // or *optarg
      }
    }

    srand(time(nullptr));
    std::vector<int> a(size);
    int i;
    for (i=0;i<size; i++){
      a[i] = rand()%max_val;
    }


    if (print) {
      print_vector(a);
      std::cout << "\n";
    }

    std::cout << "Starting the sort!\n";
    struct timeval tp;

    gettimeofday(&tp,NULL);
    long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    if (algorithm == 's'){
      a = ssort(a);
    } else if (algorithm == 'm'){
      a = msort(a);
    } else if (algorithm == 'q'){
      a = qsort(a);
    } else if (algorithm == 'i'){
      qsort2(a, 0, (a.size()-1));
    }


    gettimeofday(&tp,NULL);
    long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    long elapsed = current_time - start_time;

    if (print) {
      print_vector(a);
    }
    std::cout << "Algorithm: " << algorithm << "\n";
    std::cout << "Time: " << elapsed << "\n";



    return 0;
  }
