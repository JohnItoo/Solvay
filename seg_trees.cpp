//============================================================================
// Name        : seg_trees.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {

	int N = 4;
	int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
	cout << length;
	return 0;
}
