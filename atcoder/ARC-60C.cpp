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

	vector<vector<ll> > dp(2550, vector<ll>(n + 1, 0));
	dp[0][0] = 1;

	
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i  < n; i++) {
			for (int j = 1; j <= 2500; j++) {
				int card = x[i];
				if (card > j) continue;
				dp[j][k] += dp[j - card][k - 1];
			}

		}
	}
	for(int i = 1; i <= sm; i++) {
		for(int j = 1; j <=n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}



	ll val = 1;

	ll ans = 0;

	while (val <= n && a * val <= sm) {
		ll curr = a * val;
		ll ct = dp[curr][val];
		// cout << ct << " " << val << "\n";
		// if (val != 1) {
		// 	ct /= 2;
		// }
		val++;
		ans += ct;
	}
	cout << ans << "\n";


	return 0;
}