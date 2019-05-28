//============================================================================
// Name        : Accordian.cpp
// Author      : 
// Version     : UVA 127 -- UNNSSOOLLVVEEDD
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
string crds[27];
stack<string> arr[27];

bool suited(string a, string b) {
	return (a[0] == b[0] || a[1] == b[1]);
}

int main() {
	string cd;


	int i = 1;

	while(i <= 26) {
		cin >> cd;
		crds[i] = cd;
		arr[i].push(cd);
		i++;
	}
	int act =1;
	for(int i = 1; i<=26; i++) {
		if(crds[i] == "") continue;
		if(suited(crds[i-1],crds[i])) {
          arr[i-1].push(crds[i]);
          arr[i].pop();
          crds[i] = "";
          act = i -1;
		}
		else if(i>2 && !(suited(crds[i-1],crds[i])) && suited(crds[i-2], crds[i])) {
			arr[i-2].push(crds[i]);
			crds[i] = "";
	         arr[i].pop();
			act = i-2;
		}
		else continue;

		for(int j= i+1; j<=26; j++) {
			if(suited(crds[act],crds[j])) arr[act].push(crds[i]);
			else break;
		}
	}
	for(int i = 1; i <= 26; ++i) cout <<arr[i].size()<<" ";

	return 0;
}
