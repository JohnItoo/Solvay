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
long long n,m;


int main() {
	scanf("%lld%lld", &n,&m);
	long long sol = m/n;
	long long ans = 0;
	bool ent = false;
	while(sol>1) {
		ent = true;
		if(sol% 2 == 0 || sol%3 == 0) {
		    if (sol % 2 == 0) {
		    	sol/= 2; ans++;
		    }
		    else{
		    	sol/=3; ans++;
		    }
		} else {
			cout << -1;
			return 0;
		}
	}
	cout << (ent ? ans : -1);
	return 0;
}
