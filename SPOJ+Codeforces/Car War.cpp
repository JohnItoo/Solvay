//============================================================================
// Name        : Car.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,k1,k2,y;


int factorial(int n) {
	int ans = 0;
	int dp[1005];
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = i * dp[i-1];
	}
	return dp[n];
}

int main() {

	cin >> n;
	cin >> k1;

	queue<int> q1;
	queue<int> q2;

	int x = k1;


	while (x>0) {
     cin >>y;
     q1.push(y);
     x--;
	}

	cin >> k2;
	int z =k2;
	while (z>0) {
	     cin >>y;
	     q2.push(y);
	     z--;
	}

	int war =0;
	bool broke = false;
	while(!q2.empty() && !q1.empty()) {
		if (war >= factorial(n)) {
			broke = true;
			break;
		}
		if(q2.front() > q1.front()) {
			q2.push(q1.front());
			q2.push(q2.front());
			q1.pop();
			q2.pop();
		} else {
			q1.push(q2.front());
			q1.push(q1.front());
			q2.pop();
			q1.pop();
		}
	  war++;
	}

int won = q1.size() > q2.size() ? 1 : 2;

if (broke)  {

  cout << -1;
} else {
	cout <<war<<" " << won;
}
	return 0;
}
