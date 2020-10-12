#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int lim = 0; cin >> lim;
	priority_queue<int> q;
	for(int i  = 0; i < n-1; i++) {
       int x; cin >> x;
       q.push(x);
	}
	int bribe = 0;
	while(q.top() >= lim) {
		int curr = q.top(); q.pop();
		lim += 1;
		q.push(curr-1);
		bribe++;
	}
	cout << bribe << "\n";

	return 0;
}