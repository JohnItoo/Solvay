#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	if (n == 2) {
		cout << 6 << "\n";
		return 0;
	}

	if (k == 1 || k == n) {
		cout << 6 + ((n - 2) *  3) << "\n";

	} else {
		int lef = k - 1 - 1;
		int rig = n - k + 1;

		int steps = 0, rem = 0, mv = 0;
		int ans = 1e9 + 7;

		steps = lef;
		rem = n - k;
		int curr = 6 + (steps * 3 ) + (steps + 1) +  (rem * 3);
		ans = min(curr, ans);

		steps = rig;
		rem = k - 1;
		curr = 6 + (steps * 3 ) + (steps + 1) +  (rem * 3);
		ans = min(curr, ans);

		cout << ans << "\n";
	}

	return 0;
}