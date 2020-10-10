#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	int mx = 0;
	int M = 10e3 + 5;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	vector<vector<bool> > dp(M, vector<bool>(n + 1, 0));
	dp[0][0] = 1;

	for(int i = 0; i <= n; i++) {
		dp[0][i] = 1;
	}

	for(int i = 0; i < M; i++) {
		dp[i][0] = 1;
	}

    int ans = 0;
	for (int i = 1; i < M; i++) {
		for (int j = 1; j  <= n; j++) {
			 dp[i][j] = (a[j-1] >= i) && (j > 1 ? (dp[i][j-1] || dp[i][j-2]) : dp[i][j-1]);
			 if(i == 6) cout << dp[i][j] << " ";
			 if(j == n && dp[i][j] && dp[i][i]) ans = i;
		}

	}

	// for(int i = 0; i <= 10; i++) {
	// 	for(int j = 0; j <= n; j++) {
	// 		cout << dp[i][j] <<" ";
	// 	}
	// 	cout << "\n";
	// }

   // cout << "\n";
	cout << ans << "\n";

	//f

	return 0;
}