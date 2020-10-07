#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	int n, a; cin >> n >> a;
	vector<int> x(n);

	ll sm = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		sm += x[i];
	}

	vector<vector<ll> > dp(sm + 1, vector<ll>(n + 1, 0));
	dp[0][0] = 1;

	for (int i = 1; i <= sm; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < n; k++) {
				int card = x[k];
				if (card > i) continue;
				dp[i][j] += dp[i - card][j - 1];
			}

		}
	}

	ll val = 1;

	ll ans = 0;

	while(val <= n && 8 * val <= sm) {
		ll curr = 8 * val;
		ll ct = dp[curr][val];
		if(val != 1) {
			ct /= 2;
		}
		val++;
		ans += ct;
	}
	cout << ans << "\n";


	return 0;
}