//============================================================================
// Name        : ZeroQuantityMaximisation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int n;
int r,c;


int main() {
	scanf("%d%d", &r,&c);

	int A [r][c];
	int B [r][c];

	for(int i = 0; i<r; ++i) {
		for(int j =0; j< c; ++j) {
			cin >> A[i][j];
		}
	}

   for(int i = 0; i<r; ++i) {
		for(int j =0; j< c; ++j) {
			cin >> B[i][j];
		}
	}
	int idxR = 0;

	while (idxR < r) {
		if(A[idxR][idxR] != B[idxR][idxR]) {
			cout << "NO";
			return 0;

		}
		idxR++;
	}

	cout << "YES";
}

void solve() {
	cin >> n;
	int a[n];
	int b[n];
	int e[n];
	map<double,int> m;

	for(int i = 0; i<n; ++i) {
		cin >> a[i];
	}

	for(int i = 0; i<n; ++i) {
			cin >> b[i];
	}

	for(int i = 0; i<n; ++i) {
		double di = -(b[i]) /a[i];
		if (m.count(di)) {
		cout << m.count(di) << ": The count for " << di <<"\n";
		int c  =m.count(di) + 1;
		cout<< c << " the new value of " << di << "\n";
		m[di] = c;
		} else {
			cout   << di << " fresh di \n";
		m.insert(pair<double, int> (di,1));
		}
	}

	int idx =1;
	for (auto x : m) {
		cout << x.second << "\n";
    e[idx - 1] = x.second;
     idx++;
	}

	sort(e, e+n);

	cout << e[n-1];



}
