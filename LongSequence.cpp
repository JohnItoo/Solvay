//============================================================================
// Name        : LongSequence.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1000005];


int main() {

	scanf("%d", &n);
	for (int i = 0; i<n; ++i) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	int pres = 1;

	for (int k = 1; k < n; k++) {

	  if(a[k] >= a[k-1]) {
		  pres++;

	  }  else{
		  ans = max(pres,ans);
		  pres = 1;
	  }


// 1 2 3 4 5 5 6 6 9 5 6 3 1 3 6 6 3 2 4 6 43 245 6 3 1 4

	  }
	  ans = max(pres,ans);


	cout << ans;

}

