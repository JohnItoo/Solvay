#include <bits/stdc++.h>
using namespace std;

int leastFactor(int n) {

	for (int i = 2; i * i <= n; i++) {
		if (n % i != 0) continue;
		return i;
	}
	return n;
}

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		int lf = leastFactor(n);

		if (n == lf) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << 1 << " ";
				}
				cout << "\n";
			}
		} else {
			for (int i = 1; i <= n; i++) {
				int start = ((i + lf - 1) / lf) * lf;
				int begin = start - lf + 1;
				for (int j = 1; j < begin; j++) {
					cout << 0 << " ";
				}
				for (int j = begin; j <= start; j++) {
					cout << 1 << " ";
				}

				for (int j = start + 1; j <= n; j++) {
					cout << 0 << " ";
				}
				cout << endl;
			}

		}

	}

	return 0;
}