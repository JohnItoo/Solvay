//============================================================================
// Name        : NastyaLunch.cpp
// Author      :  Find the edges from the nth vertex to the first??
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int q [1005];
int n,m;


int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &q[i]);
	}


	int idx = 0;
	int f = 0;
	int s = 0;
	vector<int> adj[1005];

	while (idx < m) {

       scanf("%d%d", &f,&s);
//		cout << f << "  <- f : s -> " << s << "\n";
		adj[f].push_back(s);
		    adj[s].push_back(f);

		idx++;
	}

	int ans = 0;
	for(int i = n; i>=2; --i) {
		bool visit = false;
		for(auto j : adj[i]) {
			if(j == q[i-1]) { //what the fuck??

			visit = true;
//			cout << "isVisited" << j << "\n";
			  break;
			}
		}

		if (visit) {
			ans++;
		} else {12

			break;
		}
	}

	cout << ans;
	return 0;
}
