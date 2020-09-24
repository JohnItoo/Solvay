#include <bits/stdc++.h>
using namespace std;

int main() {

	priority_queue<int> pq;
	map<int, int> mp;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (mp.find(x) == mp.end()) {
			pq.push(x);
			mp[x] = 1;
		}
	}

	while (pq.size() >= 2) {

		int a = pq.top(); pq.pop();

		int b = pq.top(); pq.pop();
		cout << a << b << "\n";
		mp[a]--;
		mp[b]--;

		a -= b;

		if (mp.find(a)->second != 1) {
			pq.push(a);
			mp[a] = 1;
		}
		if (mp.find(b)->second != 1) {
			pq.push(b);
			mp[b] = 1;

		}
	}

	cout << pq.top() << endl;

	return 0;
}