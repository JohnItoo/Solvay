//============================================================================
// Name        : ToptalOshi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, sol, a[2000005];



int main() {
	cin >> n;
	for (int i =0; i <n; ++i ) {
		int d = 0;
		scanf("%d", &d);
		a[i]=d;a[n+i] = d;
	}
	int ans = 0;
	for (int i = 0; i < 2 *n  ; ++i) {
		cout<<a[i]<<": a[i] \n";
		if(a[i]) {
			ans++;
			cout<<ans<<":ans";
		}
		else {
			cout<<"sol: "<< sol<<" Ans: "<<ans<< "\n";
			sol = max(sol,ans);
			ans=0;
		}
		cout << sol << "sol :\n";

	}
	sol = max(sol, ans);
	cout<< sol;
	return 0;
}
