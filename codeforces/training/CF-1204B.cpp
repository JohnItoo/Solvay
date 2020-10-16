#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, l, r; cin >> n >> l >> r;
	int types = 1;

	 long long last = 1;
	int smn = 1;

	while (types < l ) {
		smn += (last * 2);
		last *= 2;
		types++;
	}
	smn += (n - types);
	types = 1;
	long long smx = 1;
	last  = 1;
	while (types < r) {
		smx += (last * 2);
		types++;
		last *= 2;
	}
	smx += (n - types) * last;
	cout << smn << " " << smx << "\n";


	return 0;
}