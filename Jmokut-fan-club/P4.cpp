#include <bits/stdc++.h>
using namespace std;


int main() {
	int mx = 1e9 + 8;
	vector<int> dp(60500, mx);
	dp[0] = 0;
	// dp[1] = 1;
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {

			dp[i] = min(dp[i],  dp[i - j] + 1);
		}
	}
	cout << dp[n] << "\n";

}