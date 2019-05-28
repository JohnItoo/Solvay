//============================================================================
// Name        : BalancedTeams.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

using namespace std;
int n;

int main() {

	int ans = 0;
	int j = 0;
	int sol = 1;
	scanf("%d",&n);
	int a[n];
	for(int i = 0; i<n; ++i) scanf("%d", &a[i]);

	sort(a, a+n);
	for(int i = 0; i < n;  ++i ) {
       while (j < n && a[j] - a[i] <= 5) {
    	   j++;
    	   ans = max(ans, j-i);
       }

	}

	printf("%d", sol);
	return 0;
}
