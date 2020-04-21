//============================================================================
// Name        : ThreeLittleEndians.cpp
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
vector<char> vib;



int main() {
	string id;
	bool first = true;

   while(cin >> id && id!= "#") {

	   if(next_permutation(id.begin(), id.end())) {
		   cout << id <<endl;
	   } else {
		   cout << "No Successor" << endl;
	   }
   }
	return 0;
}
