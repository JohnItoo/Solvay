//============================================================================
// Name        : Football.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
int m[1005],n,sol;

int main() {
	scanf("%d", &n);

	for(int i = 0; i< n; ++i) {
		scanf("%d", &m[i]);
	}
	 int curr = 1;
	 sol =1;
	for(int i = 0; i<n-1; ++i) {

		if(m[i] < m[i+1]){
			curr ++;
//			cout<< "increased curr";
		}
		else {
			sol = max(curr, sol); curr = 1;
		}
	}

	if((sol & 1) && sol != 1) cout << sol -1;
	else cout <<sol;
	return 0;
}
