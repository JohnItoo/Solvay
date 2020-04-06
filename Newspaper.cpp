//============================================================================
// Name        : Newspaper.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
vector<char> vc;
string s;


int main() {

	 getline(cin, s);
	    while(s != "#") {
			for(int i = 0; i<s.length(); ++i) {
				vc.push_back(s[i]);
			}
			next_permutation(vc.begin(), vc.end());

			for(int i = 0; i < s.length(); ++i) {
			  if( i== 0 && (s[i] > vc[i])) {
				cout << "No Successor";
				break;
			  }
			  cout << vc[i];
	    }
			cout << "\n";
			 getline(cin, s);
}

	return 0;
}
