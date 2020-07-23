#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n, k, p;
	cin >> n  >> k >> p;

	vector<vector<int> >plates(n, vector<int>(k, 0));

	vector<int>dp(p + 1, 0);

	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = 0; j < k; j++) {
			int y = 0; cin >> y;
			x += y;
			plates[i][j] = x;
		}
	}

	for (int i = 1; i <= p; i++) {
		for (int j = 0; j < n; j++) {
			for (int q = 0; q < i; q++) {
				if (q + 1 < i) continue;
				cout << i << " " <<  plates[j][q] << "\n";
				dp[i] = max(dp[i], dp[q + 1 - i] + plates[j][q]);
			}
		}
	}
	cout << dp[p] << "\n";
}
int main() {
	int t;
	cin >> t;
	int tests = t;
	while (t--) {
		cout << "Case #" <<  (tests - t) + 1 << ": ";
		solve();
	}
}
