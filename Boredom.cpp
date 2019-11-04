//============================================================================
// Name        : Boredom.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, a [1000005];

int solveA() {
	scanf("%d",&n);
	for(int i = 1; i <=n; ++i) scanf("%d", &a[i]);
	int sol = 0;
	int ans;

	for(int i = 1; i <=n; ++i){
		sol  = 1;
		for(auto k : a) {
			if (k ==  a[i]) {
				sol += k;
			}

		}
		ans = max(sol, ans);
	}
	cout << ans;
	return 0;
}

int cutRibbons() {
	int n, a, b,c, dp[40005];
	scanf("%d%d%d%d", &n,&a,&b,&c);
	set<int> arr;
	arr.insert(a);
	arr.insert(b);arr.insert(c);

	for(int i = 1; i<=n;++i ) {
		for (auto ct :arr ) {
			if(i - ct >= 0 ) {
				if (i - ct > 0 && dp[i-ct] <= 0) continue;
				dp[i] = max (dp[i], dp[i-ct] + 1);
			}
		}
	}

	return dp[n];
}

int main() {
	cout <<"Hello Mate!";
	int x = cutRibbons();
	cout << x ;
	return 0;
}
