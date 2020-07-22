#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b; cin >> a >> b;

	int dp[a.size() + 1][b.size() + 1];
	memset(dp, 10000000000000, sizeof dp);

	for (int i = 0; i <= a.length(); i++) {
		dp[i][0] = i;
	}
	for (int i = 0; i <= b.length(); i++) {
		dp[0][i] = i;
	}

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			int diff = a[i - 1] == b[j - 1] ? 0 : 1;
			dp[i][j] = min( min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),  dp[i - 1][j - 1] + diff);
		}
	}
	cout << dp[a.length()][b.length()];
}