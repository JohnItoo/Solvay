#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m; cin >> n >> m;
	vector<int> dp(10005, 0);

	vector<int> k(m);
	for (int i = 0; i < m; i++) {
		cin >> k[i];
		// dp[k[i]] = 0;
	}
	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + k[j] > n) continue;
			if (dp[i] == 0) {
				dp[i + k[j]] = 1;
			}
		}
	}
	if (dp[n] == 1) cout << 1 << endl;
	else cout << 2 << endl;
	return 0;
}