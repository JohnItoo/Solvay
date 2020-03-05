//============================================================================
// Name        : EhabFailsToBeThanos.cpp
// Author      : 
// Version     :https://codeforces.com/contest/1174/problem/A
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int longSolution() {
    int n;
    cin >>n;
   int upBound = n * 2;
   int arr [upBound];

    for(int i=0; i<upBound; ++i) cin >> arr[i];
    bool found = false;
	do {
		int left =0;
		int right = 0;

		for (int i = 0, j= n; i<n, j <upBound ; ++i, ++j) {
			left += arr[i];
			right += arr[j];
		}

		if (left != right){
			found = true;
			break;
		}
	}

	while(next_permutation(arr, arr+upBound));

	if(found) {
		for(auto a: arr) cout << a<< " ";
	} else {
		cout << -1;
	}
	return 1;
}

int shortSolution() {
	 int n;
	 cin >>n;
	 int upBound = n * 2;
	 int arr [upBound];

    for(int i=0; i<upBound; ++i) cin >> arr[i];
    sort(arr, arr+upBound);
	for(auto a: arr) cout << a<< " ";

	return 0;
}

int main() {
   shortSolution();
}
