#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m; cin >> n >> m;
	vector<int> k(m);
	int odds = 0; int evens = 0;
	for (int i = 0; i < m; i++) {
		cin >> k[i];
		if (k[i] & 1) odds++;
		else evens++;
	}

	if (n & 1 && evens == 0) {
		cout << 1 << "\n";
	} else if ( n % 2 == 0 && odds >= 1) {
		cout << 1 << "\n";
	} else {
		cout << 2 << "\n";
	}
	return 0;
}