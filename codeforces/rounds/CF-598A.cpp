#include <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		unsigned long long twos = 1;
		unsigned long long smt = 0;
		while(twos <= n) {
			smt += twos;
			twos *= 2;
		}
		unsigned long long ans = (n * (n+1)) / 2;
		 unsigned long long sol = ans - (2 * smt);
		cout << ans - (2 * smt) << "\n";
	}

	return 0;
}