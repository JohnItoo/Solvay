//============================================================================
// Name        : Div3C.cpp
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
	cout << "this is n :" << n<<"\n";
	for (int i =1; i <=n; ++i ) {
	     scanf("%d", &q[i]);
		}

	bool pck[2000005];
	int idx = 1;
	bool found = false;
	vector<int> res;

	while (idx < n) {
		found = false;
	for (int i =1; i <=n; ++i ) {
		if(pck[i]) continue;

		cout << "here"<<"\n";
	     if(i+q[idx] <=n && i + q[idx] <=1 ) {
	    	pck[i] = true;
	    	cout<< "found i "<< i<<"\n";
	    	res.push_back(i);
	    	found = true;
	    	idx++;
	    	break;
	     }
		}
	 if(!found) {
		 cout << -1;
		 return 0;

	 }
	}

	for(auto gy : res) {
		cout << gy << "\n";
	}

	return 0;
}
