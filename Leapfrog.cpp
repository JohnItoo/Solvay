//============================================================================
// Name        : Leapfrog.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<char> vc;

//WANTED TO PERMUTE THEN SUBSEQUENTLY CHECK VECTOR WITH THIS FUNCTION.. TOO EXPENSIVE!
bool isCorrect() {
	int sz = vc.size();

	if(vc[sz -1] != '.' || vc[0] != 'B' ) {
				return false;
	}
	bool should = true;
	for(int i = 1; i< sz-1; ++i) {
		if(vc[i] == '.' && vc[i+1] == '.') {
			should = false;
			break;
		}
	}
	return should;

}

int LeapFrog1() {
	freopen("leapfrog_ch_.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	cin >> N;

	for(int i = 1; i<=N; i++) {
		string put;
		int nB = 0;
		int nP = 0;
		cin >> put;
		int l = put.length();
		for(int i = 1; i<l; ++i) {
			if(put[i] == '.') {	nP += 1;}
			else { nB += 1;}
		}
		if(nB >= nP && nP != 0) cout <<"Case #"<<i<<":"<<" "<< "Y"<< endl;
		else cout <<"Case #"<<i<<":"<<" "<< "N"<< endl;
	}
	return 0;
}

int main() {
	freopen("leapfrog_ch_.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	cin >> N;

	for(int i = 1; i<=N; i++) {
		string put;
		int nB = 0;
		int nP = 0;
		cin >> put;
		int l = put.length();
		for(int i = 1; i<l; ++i) {
			if(put[i] == '.') {	nP += 1;}
			else { nB += 1;}
		}
		if(nB + 1 >= nP && nP != 0 && nB + 1 != 1) cout <<"Case #"<<i<<":"<<" "<< "Y"<< endl;
		else cout <<"Case #"<<i<<":"<<" "<< "N"<< endl;
	}

}
