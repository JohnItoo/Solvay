//============================================================================
// Name        : KefaAndPark.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int n,m,x,y,a[200005];
int gr[200005];
bool pk[200005];
int ct[200005];
stack<int> s;

int main() {
	scanf("%d%d", &n,&m);
	for(int i = 1; i<= n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i< n; ++i){

		scanf("%d%d", &x,&y);
		gr[y] = x;
		}

 int ans = 0;
 int idx = 1;

	for (int k = 2; k<= n; ++k){
		int g = k;
		idx = 1;
		while (g > 1) {
		ct[g] = a[g] + ct[gr[g]];
		cout << ct[g] << " ct : idx : n"<< idx << " " <<k <<"\n";
		if (ct[g] < m && gr[g] == 1) ans++;
		idx++;
		g = gr[g];

		}

	}

	cout << ans;


	return 0;
}
