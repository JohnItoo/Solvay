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
int n, sol, a[2000005], q[2000005];



int main() {
	cin >> n;
	for (int i =1; i <=n; ++i ) {
	     scanf("%d", &q[i]);
		}

	bool pck[2000005];
	int idx = 1;
	bool found = false;
	vector<int> res;

	while (idx <= n) {

	for (int i =1; i <=n; ++i ) {
		if(pck[i]) continue;
	     if(i+q[idx] <=n && i + q[idx] <=1 ) {
	    	pck[i] = true;
	    	res.push_back(i);
	    	found = true;
	    	idx++;
	    	break;
	     }
		}
	 if(!found) {
		 cout << -1<<endl;
		 return 0;

	 }
	}

	for(auto gy : res) {
		cout << gy << "\n";
	}

	return 0;
}
