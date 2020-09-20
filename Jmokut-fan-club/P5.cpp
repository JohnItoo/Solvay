#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int> > dp(n + 5, vector<int>(n + 5, 0));


	for (int steps = 2; steps < n; steps++) { // with at most this steps
		dp[i][j] = dp[i][j - 1];
		for (int k = 2; k < i; k++) {
			dp[i][j] += dp[i - k][j - 1] + 1;
		}

	}

	cout << dp[n][n] << "\n";

	return 0;
}