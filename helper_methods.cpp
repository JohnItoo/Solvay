//============================================================================
// Name        : helper_methods.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;
int n, d[100000], e[100000], sol[1000000];
float f;
vector<int> via;
vector<string> vib;
//Helper Methods

void ReadIntLine(vector<int>& numbers) {// used to read entire line of ints into vector
	string line;
	getline(cin, line);

	istringstream is(line);

	numbers = vector<int>(istream_iterator<int>(is), istream_iterator<int>());
}

void ReadDoubleLine(vector<string>& numbers) {// used to read entire line of strings into vector
	string line;
	getline(cin, line);

	istringstream is(line);

	numbers = vector<string>(istream_iterator<string>(is),
			istream_iterator<string>());
}
