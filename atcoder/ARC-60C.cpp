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

	// vector<vector<ll> > dp(2550, vector<ll>(n + 1, 0));
	ll dp[2550][n+1][n+1];
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1;


	ll ans = 0;
	for(int size = 1; size <= n; size++) {

		for(int i = 1; i <= n; i++) {
			for(int sum = 0; sum <= 2500; sum++) {
				dp[sum][size][i] += dp[sum][size][i-1];
				if(x[i-1] > sum) continue;
				dp[sum][size][i] += dp[sum - x[i-1]][size-1][i-1];
			}
			ans += dp[a*size][size][n];
		}
	}

	cout << ans << "\n";


	return 0;
}