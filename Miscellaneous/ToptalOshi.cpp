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
int n;


int main() {
	cin >> n;
	vector<int> m[1005];
	int arr[1005];
	bool sol[1005];
	int dd[1005];
	int prod[1005];
	queue<int> q;
	int x = 1;

	for(int i = 0;i<n; ++i) scanf("%d",&arr[i]);

	for(int i = 0;i<n; ++i) {
		if(arr[i] != i){
			m[i].push_back(arr[i]);
			m[arr[i]].push_back(i);
		} else {
			x = i;
		}
	}

	 // set x when arr[i] == i

	sol[x] = true;
	dd[x] = 0;
	int idx = 0;
	q.push(x);
	while(!q.empty()) {
		int s = q.front(); q.pop();

		for(auto e : m[s]) {
			if(sol[e]) continue;
			sol[e] = true;
         	dd[e] = dd[s] + 1; //increasing the number at (parent node +  1) by 1
         	prod[dd[s]+1]++;
//
//			cout << "dd[" <<s<<"]"<<":"<<dd[s]<<"\n";
//			cout << e << ":" << s << "\n";
			q.push(e);

		}
		idx++;
	}

	for(int i = 1;i<n; ++i) {
		printf("%d", prod[i]);
		}
	return 0;
}
