#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	int n; cin >> n;
	vector<int> a(n);
	int cows = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cows += a[i];
	}
	int res = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		int curr = 0;
		for (int dist = 0; dist < n; dist++) {
			curr += dist * (a[(dist + i) % n]);
		}
		res = min(curr, res);
	}
	cout << res << "\n";

	return 0;
}