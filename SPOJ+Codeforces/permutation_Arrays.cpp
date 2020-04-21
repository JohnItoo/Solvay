//============================================================================
// Name        : permutation_Arrays.cpp
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

void ReadIntLine(vector<int>& numbers) {
	string line;
	getline(cin, line);

	istringstream is(line);

	numbers = vector<int>(istream_iterator<int>(is), istream_iterator<int>());
}

void ReadDoubleLine(vector<string>& numbers) {
	string line;
	getline(cin, line);

	istringstream is(line);

	numbers = vector<string>(istream_iterator<string>(is),
			istream_iterator<string>());
}

int main() {
	int T;
	cin >> T;
	cin.ignore();

	bool first = true;
	 string blankline;

	while (T--) {

      getline(cin, blankline);

		if (!first)
			cout << "\n";
		first = false;


	    ReadIntLine(via);
	    ReadDoubleLine(vib);

	    string ans[via.size()];

	    for(int i = 0; i<via.size(); i++) {
	    	ans[via[i] - 1] = vib[i];
	    }

	    for(int i= 0; i<via.size(); i++) {
	    	cout << ans[i] <<"\n";
	    }

	}

}
